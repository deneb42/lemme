
#ifndef __GIF_IMAGE_HPP__
#define __GIF_IMAGE_HPP__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned char uint_8;
typedef unsigned int uint_32;

class GIF_image
{
	public:
		GIF_image(int x_size, int y_size);
		
		void setColor(int id, char r, char g, char b);
		void setPixel(int posX, int posY, unsigned char val) { pixels[posY][posX] = val;}
		
		char getRed(int id) const { return color[3*id]; }
		char getGreen(int id) const { return color[3*id+1]; }
		char getBlue(int id) const { return color[3*id+2]; }
		unsigned char getPixel(int posX, int posY) const { return pixels[posY][posX]; }
		
		void resize(int x, int y);
		
		void readFromFile(const char *name);
		void writeToFile(const char *name);
	
		
		static const uint_8 BLOCK_SIZE = 255;
		
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
		char* version;
		int x_size, y_size;
		vector<char> color;
		static const unsigned char backColor = '0';
	
		//contenu
		vector<vector<unsigned char> > pixels;
		static const char fin = '0';
	
		//terminator
		static const char terminator = ';';
	
};


#endif // __GIF_IMAGE_HPP__
