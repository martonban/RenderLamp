#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>

namespace RenderLamp {
    class Camera {
        public:
            Camera (const glm::dvec3& inputPos, const double& inputFov) {
                wordPos = inputPos;
                fov = inputFov;
            }

            void Process(const RenderLamp::SessionSettings& settings) {
                viewportHeight = 2.0;
                viewportWidth =  viewportHeight * (double(settings.imageWidth) / settings.imageHeight);

                // Focal Length calculation
                focalLength = viewportHeight / (2 * tan(fov/2.0));
                

                viewportU = { viewportWidth, 0.0, 0.0 };
                viewportV = { 0.0, -viewportHeight , 0.0 };

                pixelDeltaU = viewportU / double(settings.imageWidth);
                pixelDeltaV = viewportV / double(settings.imageHeight);


                glm::dvec3 viewportCorner = wordPos - glm::dvec3{0.0, 0.0, focalLength} - viewportU / 2.0 - viewportV / 2.0;
                startPixelCoord = viewportCorner + 0.5 * (pixelDeltaU + pixelDeltaV);

            }
            
            glm::dvec3 wordPos;
            double fov;
            double focalLength;
            double viewportWidth;
            double viewportHeight;
		    
            glm::dvec3 viewportU;
            glm::dvec3 viewportV;
            
            glm::dvec3 pixelDeltaU;
            glm::dvec3 pixelDeltaV;

            glm::dvec3 startPixelCoord;

            

    };
}

#endif 