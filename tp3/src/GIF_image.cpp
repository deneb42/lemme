
//

#include "GIF_image.hpp"


GIF_image::GIF_image(int x, int y)
{
	this.x_size	= x;
	this.y_size = y;
	pixels = new int[height][width];
	
	header = { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61, // GIF89a
		(uint_8)(x_size&0xff), (uint_8)(x_size>>8), // width
		(uint_8)(y_size&0xff), (uint_8)(y_size>>8), // height
		GLOBAL_COLOR_TABLE_FLAG | // use global color table
		COLOR_RESOLUTION_8_BIT |  // use 8 bit per R/G/B
		SIZE_OF_GLOBAL_COLOR_TABLE_256, // use 256 colours
		0x00, // default background colour
		0x00 };
}

GIF_image::~GIF_image()
{
	pixels.delete();
}

void GIF_image::setPixel(int posX, int posY, int val)
{
	if (val >= 0 && val <= 255)
		pixel[posY][posX] = val;
	else
		return;
	
}

//void setColor( int posX, PosY, color c)


void GIF_image::setWidth(int wid)
{
	this.width = wid;
	pixels.delete();
	pixels = new int[this.height][this.width];
}


void GIF_image::setHeight(int hei)
{
	this.height	= hei;
	pixels.delete();
	pixels = new int[this.height][this.width];
}