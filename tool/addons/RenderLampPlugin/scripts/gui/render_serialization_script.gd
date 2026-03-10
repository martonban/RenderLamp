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

func _ready():
	#_de_serialization()
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
		"Depth" = int(depth_spin_box.value)
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
		"Depth" = int(depth_spin_box.value)
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
		
		
		
func _de_serialization():
	var path := "res://RenderLampSettings.json"
	if not FileAccess.file_exists(path):
		return
	
	var file := FileAccess.open(path, FileAccess.ModeFlags.READ)
	if file == null:
		return
	
	var json_text := file.get_as_text()
	var json := JSON.new()
	var parse_result := json.parse(json_text)
	
	if parse_result != OK:
		push_error("RenderLampSettings.json parse error")
		return
	
	var data = json.data
	if typeof(data) != TYPE_DICTIONARY:
		push_error("RenderLampSettings.json is not dict")
		return

	for key in dict_editor.keys():
		if data.has(key):
			dict_editor[key] = data[key]
	
		var full_session_path: String = str(dict_editor["SessionPath"])
		var suffix := "\\SessionSettings.json"
		if full_session_path.ends_with(suffix):
			session_path_text_edit.text = full_session_path.substr(0, full_session_path.length() - suffix.length())
		else:
			session_path_text_edit.text = full_session_path

	if dict_editor.has("SessionName"):
		session_name_textEdit.text = str(dict_editor["SessionName"])
	

	if dict_editor.has("RenderEngine"):
		var id := int(dict_editor["RenderEngine"])
		var idx := render_engine_option_button.get_item_index(id)
		if idx != -1:
			render_engine_option_button.select(idx)
	
	if dict_editor.has("Mode"):
		var mode_id := int(dict_editor["Mode"])
		var mode_idx := light_sim_option_button.get_item_index(mode_id)
		if mode_idx != -1:
			light_sim_option_button.select(mode_idx)
	
	if dict_editor.has("Device"):
		var dev_id := int(dict_editor["Device"])
		var dev_idx := device_option_button.get_item_index(dev_id)
		if dev_idx != -1:
			device_option_button.select(dev_idx)
	
	if dict_editor.has("TargetWidth"):
		resulution_width.text = str(int(dict_editor["TargetWidth"]))
	if dict_editor.has("TargetHeight"):
		resolution_height.text = str(int(dict_editor["TargetHeight"]))
	
	if dict_editor.has("Samples"):
		sample_per_pixel_spin_box.value = int(dict_editor["Samples"])
	if dict_editor.has("Depth"):
		depth_spin_box.value = int(dict_editor["Depth"])
