@tool
extends Node3D

@export var node_array : Array[MeshInstance3D]
@export var camera : Camera3D


func test():
	for n in node_array:
		var material: StandardMaterial3D = n.get_active_material(0)
		var color: Color = material.albedo_color
		print("r: ", color.r, " g: ", color.g, " b: ", color.b)
	
