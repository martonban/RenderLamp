@tool
extends Node3D

@export var node_array : Array[MeshInstance3D]
@export var camera : Camera3D


func serialize():
	var camera_pos: Vector3 = camera.global_transform.origin
	var camera_fov: float = camera.fov

	var scene_data: Dictionary = {
		"camera": {
			"position": {
				"x": camera_pos.x,
				"y": camera_pos.y,
				"z": camera_pos.z
			},
			"fov": camera_fov
		},
		"objects": []
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

		var node_data: Dictionary = {
			"name": n.name,
			"type": n.mesh.get_class(),
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

	save_to_json(scene_data)


func save_to_json(data: Dictionary) -> void:
	var dict_editor : Dictionary = {
	"SessionPath" = "",
		"SessionName" = "",
		"RenderEngine" = 0,
		"Mode" = 0, 
		"Device" = 0,
		"TargetWidth" = 0,
		"TargetHeight" = 0,
		"Samples" = 0,
		"Depth" = 0
	}
	
	
	# Deserilaize Settings
	var path := "res://RenderLampSettings.json"
	if not FileAccess.file_exists(path):
		return
	
	var file_settings := FileAccess.open(path, FileAccess.ModeFlags.READ)
	if file_settings == null:
		return
	
	var json_text := file_settings.get_as_text()
	var json := JSON.new()
	var parse_result := json.parse(json_text)
	
	if parse_result != OK:
		push_error("RenderLampSettings.json parse error")
		return
	
	var data_settings = json.data
	if typeof(data_settings) != TYPE_DICTIONARY:
		push_error("RenderLampSettings.json is not dict")
		return

	var session_path: String

	for key in dict_editor.keys():
		if data_settings.has(key):
			dict_editor[key] = data_settings[key]
	
		var full_session_path: String = str(dict_editor["SessionPath"])
		var suffix := "\\SessionSettings.json"

		if full_session_path.ends_with(suffix):
			session_path = full_session_path.substr(0, full_session_path.length() - suffix.length())


	# Serialize Scene
	var json_string: String = JSON.stringify(data, "\t")
	var final_path : String = session_path + "/Scene.json"
	var file := FileAccess.open(final_path, FileAccess.WRITE)
	if file:
		file.store_string(json_string)
		file.close()
		print("Scene data saved to ", final_path)
	else:
		push_error("Failed to open file for writing: ", FileAccess.get_open_error())
