# RenderLamp
RenderLamp is a CPU path tracer engine in C++, alongside a companion DCC tool implemented as a Godot plugin.

# Editor
RenderLamp requires a DCC (Digital Content Creation) tool, which I implemented as a Godot plugin. The plugin's operation is relatively straightforward. Using Godot's MeshInstance3D, we are able to assemble a scene and export it to disk along with transformation data, organized into what are referred to as `Sessions`.
<br><br>
<img width="1919" height="1016" alt="Képernyőkép 2026-04-23 004445" src="https://github.com/user-attachments/assets/69d75296-fa87-4ae8-ad11-3a26bf77c783" />



# Rendering Engine
RenderLamp features a 3D path tracer engine, accessible through a lightweight CLI tool. This application manages rendering sessions and start render jobs. The path tracer consists of 3 main steps:

- Generating primary rays and dispatching them into the scene.
- Based on the intersection results, computing direct lighting for each pixel using shadow rays.
- Calculating indirect lighting contributions using secondary rays.

## Results:
<img width="1920" height="1080" alt="frame_0" src="https://github.com/user-attachments/assets/f8585060-b2e0-4963-a14b-9c561ae6c633" /> <br>
<img width="1920" height="1080" alt="frame_0" src="https://github.com/user-attachments/assets/47be30d8-bfa2-4183-86be-45b6c6c2501b" />


# Sources:
## Rendering Engine:
- Tomas Möller and Ben Trumbore. 2005. Fast, minimum storage ray/triangle intersection. In ACM SIGGRAPH 2005 Courses (SIGGRAPH '05). Association for Computing Machinery, New York, NY, USA, 7–es. https://doi.org/10.1145/1198555.1198746
- https://www.edmundoptics.com/knowledge-center/application-notes/imaging/understanding-focal-length-and-field-of-view/?srsltid=AfmBOoq7gCYqPvU96fcvSEI9JV5yOPyjuOgsJ2qh7ncHgr9NlJu8HiAM
- https://photo.stackexchange.com/questions/97213/finding-focal-length-from-image-size-and-fov
- https://raytracing.github.io/books/RayTracingInOneWeekend.html
- https://www.sciencedirect.com/science/article/pii/S2468502X24000457
- https://static.graphicsprogrammingconference.com/public/2025/slides/blender-cycles/Sharybin-blender-cycles-architecture-of-a-unified-cpu-gpu-path-tracer.pdf
- https://patorjk.com/software/taag/#p=display&f=Alligator2&t=RenderLamp&x=none&v=4&h=4&w=80&we=false

## RenderLamp Application:
- https://refactoring.guru/design-patterns/singleton/cpp/example
- https://refactoring.guru/design-patterns/observer/cpp/example

##Tool Development:
- https://www.youtube.com/watch?v=VyTys5oCdN8
- https://www.youtube.com/watch?v=elT8_n0_qdc
- https://www.youtube.com/watch?v=5Hog6a0EYa0
- https://www.youtube.com/watch?v=e7FXYwcDCQU
