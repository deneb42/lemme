
#ifndef ____GIF_image__
#define ____GIF_image__

#include <iostream>
#include <vector>

using namespace std;

const uint_8 GLOBAL_COLOR_TABLE_FLAG = 0x80;
const uint_8 COLOR_RESOLUTION_8_BIT = 0x70;
const uint_8 SORT_FLAG = 0x08;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_256 = 0x07;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_128 = 0x06;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_64 = 0x05;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_32 = 0x04;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_16 = 0x03;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_8 = 0x02;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_4 = 0x01;
const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_2 = 0x00;

class GIF_image
{
	public:
		GIF_image(int x_size, int y_size;
		~GIF_image();
		void setPixel(int posX, int posY, int val);
		//void setColor( int posX, PosY, color c);
		void setWidth(int wid);
		void setHeight(int hei);
	
	private:	
		uint_8 header[13];
	
		int *pixels;
		int x_size, y_size;
		char terminator = ";";
	
};


#endif // __GIF_IMAGE_HPP__
