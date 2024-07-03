#include "buzz_renderer.h"
#include "tgaimage.h"


const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(0, 0, 255, 255);

void buzz_renderer::render() {
    TGAImage image(100, 100, TGAImage::RGB);
    image.set(30, 50, red);
    image.flip_vertically();
    image.write_tga_file("output.tga");
}