@tool
extends Control

@onready var scene_list: OptionButton = $Panel/OptionButton
@onready var button: Button = $Panel/Button


func _ready():
	var items := DirAccess.get_files_at("res://RenderLamp")
	for item in items:
		if item.get_extension() == "tscn":
			scene_list.add_item(item.get_file())
	button.pressed.connect(_deserilaize)
	
func _deserilaize():
	var index = scene_list.get_selected()
	var scene = load("res://RenderLamp/" + scene_list.get_item_text(index))
	var instance: Node3D = scene.instantiate()
	add_child(instance)
	instance.serialize()
	instance.queue_free()
