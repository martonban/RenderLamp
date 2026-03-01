@tool
extends Control

@onready var serialize_button: Button = $Panel/SerializeButton
@onready var session_path_text_edit: TextEdit = $Panel/SessionPathTextEdit
@onready var render_engine_option_button: OptionButton = $Panel/RenderEngineOptionButton
@onready var light_sim_option_button: OptionButton = $Panel/LightSimOptionButton
@onready var device_option_button: OptionButton = $Panel/DeviceOptionButton
@onready var resulution_width: TextEdit = $Panel/ResulutionWidth
@onready var resolution_height: TextEdit = $Panel/ResolutionHeight
@onready var sample_per_pixel_spin_box: SpinBox = $Panel/SamplePerPixelSpinBox
@onready var depth_spin_box: SpinBox = $Panel/DepthSpinBox


func _ready():
	serialize_button.pressed.connect(_on_serialization)
	
func _on_serialization():
	var full_path = session_path_text_edit.text + "\\SessionSettings.json"
	var dict : Dictionary = {
		"RenderEngine" = render_engine_option_button.get_item_id(render_engine_option_button.selected),
		"Mode" = light_sim_option_button.get_item_id(light_sim_option_button.selected),
		"Device" = device_option_button.get_item_id(device_option_button.selected),
		"TargetWidth" = resulution_width.text,
		"TargetHeight" = resolution_height.text,
		"Samples" = sample_per_pixel_spin_box.value,
		"Depth" = depth_spin_box.value
	}
	
	var file = FileAccess.open(full_path, FileAccess.ModeFlags.WRITE)
	if file:
		var json_text = JSON.stringify(dict, "\t")
		file.store_string(json_text)
