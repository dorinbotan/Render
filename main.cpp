#include "tgaimage.h"
#include "pen.h"
#include "model.h"
#include "geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

Model *model = NULL;

const int width  = 200;
const int height = 200;

int main(int argc, char** argv) {
    TGAImage image(width, height, TGAImage::RGB);

    // if (2 == argc) {
    //     model = new Model(argv[1]);
    // } else {
    //     model = new Model("obj/african_head.obj");
    // }

    // for (int i=0; i<model->nfaces(); i++) {
    //     std::vector<int> face = model->face(i);
    //     for (int j=0; j<3; j++) {
    //         Vec3f v0 = model->vert(face[j]);
    //         Vec3f v1 = model->vert(face[(j+1)%3]);
    //         int x0 = (v0.x+1.)*width/2.;
    //         int y0 = (v0.y+1.)*height/2.;
    //         int x1 = (v1.x+1.)*width/2.;
    //         int y1 = (v1.y+1.)*height/2.;
    //         drawLine(x0, y0, x1, y1, image, white);
    //     }
    // }

    drawRect(0, 0, width - 1, height - 1, image, white);
    drawLine(20, 20, 100, 100, image, red);

    // image.flip_vertically();
	image.write_tga_file("output.tga");
	return 0;
}
