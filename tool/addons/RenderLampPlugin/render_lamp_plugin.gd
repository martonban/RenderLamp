@tool
extends EditorPlugin

var render_button

func _enable_plugin() -> void:
	# Add autoloads here.
	pass


func _disable_plugin() -> void:
	# Remove autoloads here.
	pass


func _enter_tree() -> void:
	var icon = preload("res://addons/RenderLampPlugin/assets/icons/logo_16_white.png")
	render_button = Button.new()
	render_button.icon = icon
	render_button.flat = true
	add_control_to_container(CONTAINER_TOOLBAR, render_button)
	


func _exit_tree() -> void:
	# Clean-up of the plugin goes here.
	remove_control_from_container(CONTAINER_TOOLBAR, render_button)
	render_button.queue_free()
