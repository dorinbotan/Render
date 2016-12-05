#include "tgaimage.h"
#include "pen.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);

	drawLine(0, 0, 100, 20, image, red);
	drawLine(0, 0, 20, 100, image, red);

	image.write_tga_file("output.tga");
	return 0;
}
