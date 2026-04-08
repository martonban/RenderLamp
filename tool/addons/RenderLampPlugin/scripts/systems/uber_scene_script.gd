@tool
extends Node3D

@export var node_array : Array[MeshInstance3D]
@export var light_array : Array[OmniLight3D]
@export var camera : Camera3D
@export var animation_node : AnimationPlayer


func serialize():
	# Scene Serializazion
	var scene := serilaize_scene()
	var batches := serialize_animation()
	
	save_to_json(scene, batches)


func save_to_json(data: Dictionary, data_batches: Dictionary) -> void:
	var dict_editor : Dictionary = {
		"SessionPath": "",
		"SessionName": "",
		"RenderEngine": 0,
		"Mode": 0, 
		"Device": 0,
		"TargetWidth": 0,
		"TargetHeight": 0,
		"Samples": 0,
		"Depth": 0
	}
	
	
	# Deserilaize Settings
	var path := "res://RenderLampSettings.json"
	if not FileAccess.file_exists(path):
		return
	
	var file_settings := FileAccess.open(path, FileAccess.ModeFlags.READ)
	if file_settings == null:
		return
	
	var json_text := file_settings.get_as_text()
	file_settings.close()
	var json := JSON.new()
	var parse_result := json.parse(json_text)
	
	if parse_result != OK:
		push_error("RenderLampSettings.json parse error")
		return
	
	var data_settings = json.data
	if typeof(data_settings) != TYPE_DICTIONARY:
		push_error("RenderLampSettings.json is not dict")
		return

	var session_path: String = ""

	for key in dict_editor.keys():
		if data_settings.has(key):
			dict_editor[key] = data_settings[key]

	var full_session_path: String = str(dict_editor["SessionPath"])
	var suffix := "\\SessionSettings.json"

	if full_session_path.ends_with(suffix):
		session_path = full_session_path.substr(0, full_session_path.length() - suffix.length())

	if session_path.is_empty():
		push_error("SessionPath is empty or invalid!")
		return

	# Serialize Scene
	var json_string: String = JSON.stringify(data, "\t")
	var final_path : String = session_path + "/Scene.json"
	var file := FileAccess.open(final_path, FileAccess.WRITE)
	if file:
		file.store_string(json_string)
		file.close()
		print("Scene data saved to ", final_path)
	else:
		push_error("Failed to open file for writing: %s (error: %s)" % [final_path, FileAccess.get_open_error()])

	var json_string2: String = JSON.stringify(data_batches, "\t")
	var final_path2 : String = session_path + "/Batches.json"
	var file2 := FileAccess.open(final_path2, FileAccess.WRITE)
	if file2:
		file2.store_string(json_string2)
		file2.close()
		print("Batches data saved to ", final_path2)
	else:
		push_error("Failed to open file for writing: %s (error: %s)" % [final_path2, FileAccess.get_open_error()])


func serilaize_scene() -> Dictionary:
	var camera_pos: Vector3 = camera.global_transform.origin
	var camera_rot: Vector3 = camera.global_rotation_degrees 
	var camera_fov: float = camera.fov

	var scene_data: Dictionary = {
		"camera": {
			"position": {
				"x": camera_pos.x,
				"y": camera_pos.y,
				"z": camera_pos.z
			},
			"rotation" : {
				"x": camera_rot.x,
				"y": camera_rot.y,
				"z": camera_rot.z
			},
			"fov": camera_fov
		},
		"objects": [],
		"lights": []
	}

	for n in node_array:
		if not n.is_inside_tree():
			push_warning("Node is not inside tree yet: ", n.name)
			continue
		var world_pos: Vector3 = n.global_transform.origin
		var world_rot: Vector3 = n.global_transform.basis.get_euler()
		var world_scale: Vector3 = n.global_transform.basis.get_scale()

		var material: StandardMaterial3D = n.get_active_material(0)
		var color: Vector3i = Vector3i(
			int(material.albedo_color.r * 255),
			int(material.albedo_color.g * 255),
			int(material.albedo_color.b * 255)
		)
		var metallic_value: float = material.metallic
		var roughness_value: float = material.roughness
		
		var model_path: String = ""
		if n.mesh != null and n.mesh.resource_path != "":
			model_path = ProjectSettings.globalize_path(n.mesh.resource_path)
		else:
			model_path = ""

		var node_data: Dictionary = {
			"id": node_array.find(n),
			"type": n.mesh.get_class(),
			"model_path": model_path,
			
			"transform": {
				"position": {
					"x": world_pos.x,
					"y": world_pos.y,
					"z": world_pos.z
				},
				"rotation": {
					"x": world_rot.x,
					"y": world_rot.y,
					"z": world_rot.z
				},
				"scale": {
					"x": world_scale.x,
					"y": world_scale.y,
					"z": world_scale.z
				}
			},
			"material": {
				"color": {
					"r": color.x,
					"g": color.y,
					"b": color.z
				},
				"metallic": metallic_value,
				"roughness": roughness_value
			}
		}
		scene_data["objects"].append(node_data)
		
	for l in light_array:
		if not l.is_inside_tree():
			push_warning("Node is not inside tree yet: ", l.name)
			continue
		var world_pos: Vector3 = l.global_transform.origin
		var light_color: Color = l.light_color
		var intensity: float = l.light_energy
		var light_range: float = l.omni_range
		var attenuation: float = l.omni_attenuation
		
		var light_data: Dictionary = {
			"id": light_array.find(l),
			"position": {
				"x": world_pos.x,
				"y": world_pos.y,
				"z": world_pos.z
			},
			"color" : {
				"r": light_color.r,
				"g": light_color.g,
				"b": light_color.b
			},
			
			"intensity": intensity,
			"range": light_range,
			"attenuation": attenuation
		}
		scene_data["lights"].append(light_data)
	
	return scene_data


func serialize_animation() -> Dictionary:
	if animation_node == null:
		return {}
	
	var result: Dictionary = {}
	var animation_list: PackedStringArray = animation_node.get_animation_list()
	
	for animation_name in animation_list:
		var animation: Animation = animation_node.get_animation(animation_name)
		var animation_metadata: Dictionary = {
			"length": animation.length,
			"tracks": []
		} 
	

		for track_idx in range(animation.get_track_count()):
			var track_path: NodePath = animation.track_get_path(track_idx)
			var node_path_str: String = str(track_path)
			var colon_idx: int = node_path_str.find(":")
			var pure_node_path: String = node_path_str
			if colon_idx != -1:
				pure_node_path = node_path_str.substr(0, colon_idx)
			
			var root_node: Node = animation_node.get_node(animation_node.root_node)
			var target_node: Node = root_node.get_node_or_null(NodePath(pure_node_path))
			
			var mesh_index: int = -1
			if target_node is MeshInstance3D:
				mesh_index = _find_mesh_index(target_node as MeshInstance3D)
			
			if mesh_index == -1:
				continue
			
			var track_type: int = animation.track_get_type(track_idx)
			var track_data: Dictionary = {
				"mesh_id": mesh_index,
				"type": _track_type_to_string(track_type),
				"keyframes": []
			}
			
			var key_count: int = animation.track_get_key_count(track_idx)
			for key_idx in range(key_count):
				var time: float = animation.track_get_key_time(track_idx, key_idx)
				var value = animation.track_get_key_value(track_idx, key_idx)
				var transition: float = animation.track_get_key_transition(track_idx, key_idx)

				# HIBA 3: _value_to_serializable() hívás hiányzott!
				var keyframe_data: Dictionary = {
					"time": time,
					"value": _value_to_serializable(value),
					"transition": transition
				}
			
				track_data["keyframes"].append(keyframe_data)

			animation_metadata["tracks"].append(track_data)
		
		result[animation_name] = animation_metadata
	
	return result
	
	
func _find_mesh_index(mesh: MeshInstance3D) -> int:
	if mesh == null:
		return -1
	for i in range(node_array.size()):
		if node_array[i] != null and node_array[i].get_instance_id() == mesh.get_instance_id():
			return i
	return -1


func _track_type_to_string(track_type: int) -> String:
	match track_type:
		Animation.TYPE_VALUE:
			return "value"
		Animation.TYPE_POSITION_3D:
			return "position_3d"
		Animation.TYPE_ROTATION_3D:
			return "rotation_3d"
		Animation.TYPE_SCALE_3D:
			return "scale_3d"
		_:
			return "unknown"


func _value_to_serializable(value) -> Variant:
	if value is Vector3:
		return {"x": value.x, "y": value.y, "z": value.z}
	elif value is Quaternion:
		return {"x": value.x, "y": value.y, "z": value.z, "w": value.w}
	elif value is Transform3D:
		return {
			"basis": {
				"x": {"x": value.basis.x.x, "y": value.basis.x.y, "z": value.basis.x.z},
				"y": {"x": value.basis.y.x, "y": value.basis.y.y, "z": value.basis.y.z},
				"z": {"x": value.basis.z.x, "y": value.basis.z.y, "z": value.basis.z.z}
			},
			"origin": {"x": value.origin.x, "y": value.origin.y, "z": value.origin.z}
		}
	elif value is Color:
		return {"r": value.r, "g": value.g, "b": value.b, "a": value.a}
	elif value is Vector2:
		return {"x": value.x, "y": value.y}
	elif value is float or value is int or value is String or value is bool:
		return value
	else:
		return str(value)
