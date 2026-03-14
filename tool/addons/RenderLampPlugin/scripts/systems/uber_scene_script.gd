@tool
extends Node3D

@export var node_array : Array[MeshInstance3D]
@export var camera : Camera3D


func serialize():
	var camera_pos: Vector3 = camera.global_transform.origin
	var camera_fov: float = camera.fov
		
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
		
