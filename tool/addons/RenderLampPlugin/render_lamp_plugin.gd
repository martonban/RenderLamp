@tool
extends EditorPlugin

# RenderLamp Button
var render_button
var gui_render_lamp_button := preload("uid://cy0sy7m4q2hrb")
var window : Window

# RenderLamp Serialization 
var project_settings_scene: Control
var gui_serialization := preload("uid://ixgi0wh4w6cq")

# RenderLamp Toolbox
var toolbox_scene: Control
var gui_toolbox := preload("uid://dtyh78wdl1ckw")

func _enable_plugin() -> void:
	# Add autoloads here.
	pass


func _disable_plugin() -> void:
	# Remove autoloads here.
	pass


func _enter_tree() -> void:
	# Project Settings
	project_settings_scene = gui_serialization.instantiate()
	project_settings_scene.name = "RenderLamp Settings"
	add_control_to_container(CONTAINER_PROJECT_SETTING_TAB_RIGHT, project_settings_scene)
	
	# Render Scene Button
	var icon = preload("res://addons/RenderLampPlugin/assets/icons/logo_16_white.png")
	render_button = Button.new()
	render_button.icon = icon
	render_button.flat = true
	add_control_to_container(CONTAINER_TOOLBAR, render_button)
	
	# RenderLamp Toolbox
	toolbox_scene = gui_toolbox.instantiate()
	toolbox_scene.name = "RenderLamp"
	add_control_to_dock(DOCK_SLOT_LEFT_BR, toolbox_scene)

	render_button.pressed.connect(_open_render_lamp_serialiazation_window)
	

func _exit_tree() -> void:
	# Clean-up of the plugin goes here.
	remove_control_from_container(CONTAINER_PROJECT_SETTING_TAB_RIGHT, project_settings_scene)
	project_settings_scene.queue_free()
	
	# Clean-up Render Scene Button
	remove_control_from_container(CONTAINER_TOOLBAR, render_button)
	render_button.queue_free()
	
	remove_control_from_docks(toolbox_scene)
	toolbox_scene.queue_free()


func _open_render_lamp_serialiazation_window():
	window = Window.new()
	window.title = "RenderLamp"
	
	window.wrap_controls = true
	var gui_scene = gui_render_lamp_button.instantiate()
	if gui_scene is Control:
		gui_scene.set_anchors_and_offsets_preset(Control.PRESET_FULL_RECT)
	
	window.add_child(gui_scene)
	EditorInterface.popup_dialog(window, Rect2(Vector2(200, 200), Vector2(500, 600)))

	
	# Connect Signals
	window.close_requested.connect(func(): 
		window.queue_free()
	)
