import bpy


# ─────────────────────────────────────────────
#  Panel
# ─────────────────────────────────────────────

class RENDERLAMP_PT_Panel(bpy.types.Panel):
    bl_label       = "RenderLamp"
    bl_idname      = "RENDERLAMP_PT_panel"
    bl_space_type  = "VIEW_3D"
    bl_region_type = "UI"
    bl_category    = "RenderLamp"

    def draw(self, context: bpy.types.Context) -> None:
        layout = self.layout
        layout.label(text="RenderLamp is ready!", icon="RENDER_STILL")
        layout.separator()
        layout.operator("renderlamp.hello", icon="CONSOLE")


# ─────────────────────────────────────────────
#  Operator
# ─────────────────────────────────────────────

class RENDERLAMP_OT_Hello(bpy.types.Operator):
    bl_idname  = "renderlamp.hello"
    bl_label   = "Say Hello"
    bl_description = "Prints a message to the Info log"

    def execute(self, context: bpy.types.Context):
        self.report({"INFO"}, "Hello from RenderLamp!")
        return {"FINISHED"}


# ─────────────────────────────────────────────
#  Register / Unregister
# ─────────────────────────────────────────────

_CLASSES = (
    RENDERLAMP_PT_Panel,
    RENDERLAMP_OT_Hello,
)


def register() -> None:
    for cls in _CLASSES:
        bpy.utils.register_class(cls)


def unregister() -> None:
    for cls in reversed(_CLASSES):
        bpy.utils.unregister_class(cls)


if __name__ == "__main__":
    register()
