
//

#include "GIF_image.hpp"


GIF_image::GIF_image(int x, int y)
{
	this.x_size	= x;
	this.y_size = y;
	pixels.resize(y_size); // dimensionnement de la hauteur
	
	for (std::vector<std::vector<char> >::iterator it = pixels.begin(); it != pixels.end() ; it++) {
		it.resize(x_size);
	} //dimensionnement de la largeur de chaque ligne.
	
}

void GIF_image::setPixel(int posX, int posY, unsigned char val)
{
	pixels[posY][posX] = val;
	
}

void GIF_image::resize(int x, int y)
{
	for (std::vector<vector<char> >::iterator it = pixels.begin(); it != pixels.end() ; it++) {
		it.resize(x);
	} //dimensionnement de la largeur de chaque ligne.

	x_size = x;
	
	pixels.resize(y);
	y_size = y;
	
}

void GIF_image::readFromFile(const char *name)
{
	
}
void GIF_image::writeToFile(const char *name)
{
	
}
