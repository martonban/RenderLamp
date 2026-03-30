@tool
extends Control

@onready var save_button: Button = $Panel/SaveButton
@onready var session_name_textEdit: TextEdit = $Panel/SessionNameTextEdit
@onready var session_path_text_edit: TextEdit = $Panel/SessionPathTextEdit
@onready var render_engine_option_button: OptionButton = $Panel/RenderEngineOptionButton
@onready var light_sim_option_button: OptionButton = $Panel/LightSimOptionButton
@onready var device_option_button: OptionButton = $Panel/DeviceOptionButton
@onready var resulution_width: TextEdit = $Panel/ResulutionWidth
@onready var resolution_height: TextEdit = $Panel/ResolutionHeight
@onready var sample_per_pixel_spin_box: SpinBox = $Panel/SamplePerPixelSpinBox
@onready var depth_spin_box: SpinBox = $Panel/DepthSpinBox
@onready var frame_rate_spin_box: SpinBox = $Panel/FramerateSpinBox

var dict_editor : Dictionary = {
	"SessionPath" = "",
	"SessionName" = "",
	"RenderEngine" = 0,
	"Mode" = 0, 
	"Device" = 0,
	"TargetWidth" = 0,
	"TargetHeight" = 0,
	"Samples" = 0,
	"Depth" = 0,
	"FrameRate" = 0
}

func _ready():
	save_button.pressed.connect(_on_serialization)

	
func _on_serialization():
	var dict : Dictionary = {
		"SessionName" = session_name_textEdit.text,
		"RenderEngine" = render_engine_option_button.get_item_id(render_engine_option_button.selected),
		"Mode" = light_sim_option_button.get_item_id(light_sim_option_button.selected),
		"Device" = device_option_button.get_item_id(device_option_button.selected),
		"TargetWidth" = int(resulution_width.text),
		"TargetHeight" = int(resolution_height.text),
		"Samples" = int(sample_per_pixel_spin_box.value),
		"Depth" = int(depth_spin_box.value),
		"FrameRate" = int(frame_rate_spin_box.value)
	}
	
	var dict_editor : Dictionary = {
		"SessionPath" = session_path_text_edit.text + "\\SessionSettings.json",
		"SessionName" = session_name_textEdit.text,
		"RenderEngine" = render_engine_option_button.get_item_id(render_engine_option_button.selected),
		"Mode" = light_sim_option_button.get_item_id(light_sim_option_button.selected),
		"Device" = device_option_button.get_item_id(device_option_button.selected),
		"TargetWidth" = int(resulution_width.text),
		"TargetHeight" = int(resolution_height.text),
		"Samples" = int(sample_per_pixel_spin_box.value),
		"Depth" = int(depth_spin_box.value),
		"FrameRate" = int(frame_rate_spin_box.value)
	}
	
	var full_path = session_path_text_edit.text + "\\SessionSettings.json"
	var file = FileAccess.open(full_path, FileAccess.ModeFlags.WRITE)
	if file:
		var json_text = JSON.stringify(dict, "\t")
		file.store_string(json_text)
		
	var file2 = FileAccess.open("res://RenderLampSettings.json", FileAccess.ModeFlags.WRITE)
	if file2:
		var json_text2 = JSON.stringify(dict_editor, "\t")
		file2.store_string(json_text2)
