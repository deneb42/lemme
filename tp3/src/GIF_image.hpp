
#ifndef ____GIF_image__
#define ____GIF_image__

#include <iostream>
#include <vector>

using namespace std;

class GIF_image
{
	public:
		GIF_image(int x_size, int y_size);
	void setPixel(int posX, int posY, unsigned char val){pixels[posY][posX] = val;};
		void resize(int x, int y);
	
	
		static const uint_8 GLOBAL_COLOR_TABLE_FLAG = 0x80;
		static const uint_8 COLOR_RESOLUTION_8_BIT = 0x70;
		static const uint_8 SORT_FLAG = 0x08;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_256 = 0x07;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_128 = 0x06;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_64 = 0x05;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_32 = 0x04;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_16 = 0x03;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_8 = 0x02;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_4 = 0x01;
		static const uint_8 SIZE_OF_GLOBAL_COLOR_TABLE_2 = 0x00;

	private:
	
		//header
		static const string version = "GIF89a";
		unsigned int x_size, y_size;
		static const unsigned char backColor = '0';
	
		//contenu
		vector<vector<unsigned char> > pixels;
		static const char fin = '0';
	
		//terminator
		const char terminator = ";";
	
};


#endif // __GIF_IMAGE_HPP__
