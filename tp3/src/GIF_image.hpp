
#ifndef __GIF_IMAGE_HPP__
#define __GIF_IMAGE_HPP__

	#include <iostream>
	#include <vector>
	
	using namespace std;
	
	class GIF_image
	{
		public:
			GIF_image(int width, int height);
			void setPixel(int posX, int PosY, int val);
			void setColor( int posX, PosY, color c);
			void setWidth(int wid);
			void setHeight(int hei);
		
		private:	
			uint_8 header[13] = { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61, // GIF89a
				(uint_8)(x_size&0xff), (uint_8)(x_size>>8), // width
				(uint_8)(y_size&0xff), (uint_8)(y_size>>8), // height
				GLOBAL_COLOR_TABLE_FLAG | // use global color table
				COLOR_RESOLUTION_8_BIT |  // use 8 bit per R/G/B
				SIZE_OF_GLOBAL_COLOR_TABLE_256, // use 256 colours
				0x00, // default background colour
				0x00 };
		
			int *pixels;		
		
	};

#endif // __GIF_IMAGE_HPP__
