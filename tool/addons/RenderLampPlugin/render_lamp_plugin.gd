@tool
extends EditorPlugin

var render_button
var render_lamp_menu_bar

func _enable_plugin() -> void:
	# Add autoloads here.
	pass


func _disable_plugin() -> void:
	# Remove autoloads here.
	pass


func _enter_tree() -> void:
	# Menu Bar
	render_lamp_menu_bar = MenuButton.new()
	render_lamp_menu_bar.text = "RenderLamp"
	render_lamp_menu_bar.flat = true

	var menu = render_lamp_menu_bar.get_popup()
	menu.add_item("Setup")
	menu.add_item("Connect")
	
	add_control_to_container(CONTAINER_SPATIAL_EDITOR_MENU ,render_lamp_menu_bar)
	
	# Render Scene Button
	var icon = preload("res://addons/RenderLampPlugin/assets/icons/logo_16_white.png")
	render_button = Button.new()
	render_button.icon = icon
	render_button.flat = true
	add_control_to_container(CONTAINER_TOOLBAR, render_button)
	


func _exit_tree() -> void:
	# Clean-up of the plugin goes here.
	remove_control_from_container(CONTAINER_SPATIAL_EDITOR_MENU, render_lamp_menu_bar)
	render_lamp_menu_bar = null
	
	# Clean-up Render Scene Button
	remove_control_from_container(CONTAINER_TOOLBAR, render_button)
	render_button.queue_free()
