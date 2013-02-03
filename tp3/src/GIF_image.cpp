#include "GIF_image.hpp"
#include <fstream>
#include <sstream>
#include "olzwstream.hpp"


GIF_image::GIF_image(int x, int y)
{
	x_size	= x;
	y_size = y;
	//version = 0x47, 0x49, 0x46, 0x38, 0x39, 0x61; // {'G', 'I', 'F','8', '9', 'a'};
	pixels.resize(y_size); // dimensionnement de la hauteur
	

	for (unsigned int i=0;i<pixels.size();i++) {
		pixels.resize(x_size);
	} //dimensionnement de la largeur de chaque ligne.
	
}

void setColor(int id, char r, char g char b)
{
	color[3*id] = r; 
	color[3*id+1] = g; 
	color[3*id+2] = b; 
}

void GIF_image::resize(int x, int y)
{
	for (std::vector<vector<unsigned char> >::iterator it = pixels.begin(); it != pixels.end() ; it++) {
		it->resize(x);
	} //dimensionnement de la largeur de chaque ligne.

	x_size = x;
	
	pixels.resize(y);
	y_size = y;
	
}

void GIF_image::readFromFile(const char *name)
{
	uint_8 header[13] = 
		{ 	0x47, 0x49, 0x46, 0x38, 0x39, 0x61, // GIF89a
			(uint_8)(x_size&0xff), (uint_8)(x_size>>8), // width
			(uint_8)(y_size&0xff), (uint_8)(y_size>>8), // height
			GLOBAL_COLOR_TABLE_FLAG | // use global color table
			COLOR_RESOLUTION_8_BIT |  // use 8 bit per R/G/B
			SIZE_OF_GLOBAL_COLOR_TABLE_256, // use 256 colours
			0x00, // default background colour
			0x00 
		};
      
	std::ofstream out(name);

	out.write((char*)header, 13); // write Header
	out.write(col_data, 3*(1ul << (SIZE_OF_GLOBAL_COLOR_TABLE_256+1))); // write Global Colour Table
	out.put(0x2c); // start Image Descriptor
	out.put(0x00);
	out.put(0x00);
	out.put(0x00);
	out.put(0x00);
	out.write((char*)(header+6), 4);
	out.put(0x00); // start of image

	uint_8 code_size = 1+SIZE_OF_GLOBAL_COLOR_TABLE_256;

	out.put(code_size); // LZW minimum code size

	std::ostringstream str;

	// encode img_data
	{
		olzwstream lzw(&str);
		for (int i = 0; i < y_size; i++)
			for (int j = 0; j < x_size; j++)
				lzw.put(pixels[i][j]);
		lzw.close();
	}

	const std::string& obj = str.str();
	const char* ptr = obj.c_str();
	int size = obj.size();

	// write encoded data as chunks of BLOCK_SIZE bytes
	for (int i = 0; i < size/BLOCK_SIZE; i++) 
	{
		out.put(BLOCK_SIZE);
		out.write(ptr, BLOCK_SIZE);
		ptr += BLOCK_SIZE;
	}

	// write remaining bytes
	if (size%BLOCK_SIZE != 0) 
	{
		out.put(size%BLOCK_SIZE);
		out.write(ptr, size%BLOCK_SIZE);
	}

	out.put(0x00);
	out.put(0x3b); // GIF file terminator
}

void GIF_image::writeToFile(const char *name)
{
	uint_8 header[13] =
    {   0x47, 0x49, 0x46, 0x38, 0x39, 0x61,
		(uint_8)(x_size&0xff), (uint_8)(x_size>>8), // width
		(uint_8)(y_size&0xff), (uint_8)(y_size>>8), // height
		GLOBAL_COLOR_TABLE_FLAG | // use global color table
		COLOR_RESOLUTION_8_BIT |  // use 8 bit per R/G/B
		SIZE_OF_GLOBAL_COLOR_TABLE_256, // use 256 colours
		(uint_8) backColor,
		0x00 };
	
	std::ofstream out(name);
	
	out.write((char*)header, 13); // write Header
	out.write(color.data(), 3*(1ul << (SIZE_OF_GLOBAL_COLOR_TABLE_256+1))); // write Global Colour Table
	out.put(0x2c); // start Image Descriptor
	out.put(0x00);
	out.put(0x00);
	out.put(0x00);
	out.put(0x00);
	out.write((char*)(header+6), 4);
	out.put(0x00); // start of image
	
	uint_8 code_size = 1+SIZE_OF_GLOBAL_COLOR_TABLE_256;

	out.put(code_size); // LZW minimum code size

	std::ostringstream str;

	// encode img_data
	{
		olzwstream lzw(&str);
		for (int i = 0; i < y_size; i++)
			for (int j = 0; j < x_size; j++)
				lzw.put(pixels[i][j]);
		lzw.close();
	}

	const std::string& obj = str.str();
	const char* ptr = obj.c_str();
	int size = obj.size();

	// write encoded data as chunks of BLOCK_SIZE bytes
	for (int i = 0; i < size/BLOCK_SIZE; i++) 
	{
	
	// write remaining bytes
	if (size%BLOCK_SIZE != 0) {
		out.put(size%BLOCK_SIZE);
		out.write(ptr, size%BLOCK_SIZE);
	}
	
	out.put(0x00);
	out.put(0x3b); // GIF file terminator


	// write remaining bytes
	if (size%BLOCK_SIZE != 0) 
	{
		out.put(size%BLOCK_SIZE);
		out.write(ptr, size%BLOCK_SIZE);
	}

	out.put(0x00);
	out.put(0x3b); // GIF file terminator

	}
}
