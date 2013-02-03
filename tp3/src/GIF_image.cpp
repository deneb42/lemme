#include "GIF_image.hpp"
#include <fstream>
#include <sstream>
#include "olzwstream.hpp"
#include "ilzwstream.hpp"

using namespace std;


GIF_image::GIF_image(int x, int y) : x_size(x), y_size(y), backColor(0)
{
	//version = 0x47, 0x49, 0x46, 0x38, 0x39, 0x61; // {'G', 'I', 'F','8', '9', 'a'};

	pixels.resize(y_size); // dimensionnement de la hauteur
	color.resize(3*256);
	
	for (unsigned int i=0;i<pixels.size();i++) {
		pixels[i].resize(x_size);
	} //dimensionnement de la largeur de chaque ligne.

}

void GIF_image::setColor(int id, char r, char g,char b)
{
	color[3*id] = r; 
	color[3*id+1] = g; 
	color[3*id+2] = b; 
}

void GIF_image::resize(int x, int y)
{
	for (std::vector<vector<char> >::iterator it = pixels.begin(); it != pixels.end() ; it++) {
		it->resize(x);
	} //dimensionnement de la largeur de chaque ligne.

	x_size = x;
	
	pixels.resize(y);
	y_size = y;
	
}

void GIF_image::stamp()
{
	setColor(255, char(255), 0, 0);
	
	if(x_size < 50 || y_size < 100) // if the image is too small, just crossed lines
	{
		for(int i=0;i<x_size;i++)
			setPixel(i, y_size/2,255);
			
		for(int i=0;i<y_size;i++)
			setPixel(x_size/2, i,255);
	}
	else // else we can play
	{
		for(int i=y_size/2-30;i<y_size/2-5;i++)
		{
			setPixel(x_size/2-15, i,255);
			setPixel(x_size/2-16, i,255);
			setPixel(x_size/2-17, i,255);
			
			setPixel(x_size/2+15, i,255);
			setPixel(x_size/2+16, i,255);
			setPixel(x_size/2+17, i,255);
		}
		for(int i=0;i<10;i++)
		{
			setPixel(i+x_size/2-20, y_size/2+17,255);
			setPixel(i+x_size/2-20, y_size/2+18,255);
			setPixel(i+x_size/2-20, y_size/2+19,255);
			
			setPixel(x_size/2+20-i, y_size/2+17,255);
			setPixel(x_size/2+20-i, y_size/2+18,255);
			setPixel(x_size/2+20-i, y_size/2+19,255);
		}
		for(int i=x_size/2-10;i<x_size/2+10;i++)
		{
			setPixel(i, y_size/2+20,255);
			setPixel(i, y_size/2+21,255);
			setPixel(i, y_size/2+22,255);
		}
	}
}

bool GIF_image::readFromFile(const char *name) // ajout de gestion d'un fichier trop petit
{
	std::ifstream in(name);
	const uint_8 gif[] = "GIF89a";
	char buf[7], ch;
	int tmp, c;
	std::cout << "toto 5" << std::endl;
	
	if(!in.good())
	{
		std::cerr << "file unreachable" << std::endl;
		return false;
	}
	
	in.read(buf, 6); // getting GIF89a
	
	for(int i=0;i<6;i++)
		if(buf[i] != gif[i])
		{
			if(i==5 && buf[i]!='7') // for the older version
			{
				std::cerr << "file is not a gif" << std::endl;
				return false;
			}
		}
	
	//for now, we know that the file is reachable and is a gif
	
	in.read(buf, 4); //getting the sizes
	
	resize((int(buf[1])<<8)|((uint_8)(buf[0])), (int(buf[3])<<8)|((uint_8)(buf[2]))); // to rebuild the sizes. May be simpler but it works
	
	if(in.get() != (GLOBAL_COLOR_TABLE_FLAG | COLOR_RESOLUTION_8_BIT | SIZE_OF_GLOBAL_COLOR_TABLE_256))
	{
		std::cerr << "Software under developement, \nfor the time being only Global Color Table, 8bit/color, 256 color accepted" << std::endl;
		return false;
	}
	
	backColor = in.get();
	in.get(); // there is one more byte of header, but i don't know what's its meaning
	
	for(int i=0;i<256;i++)
	{
		in.read(buf, 3);
		setColor(i, buf[0], buf[1], buf[2]);
	}
	
	if(in.get() != 0x2c)
	{
		std::cerr << "File misformed (no Image Descriptor delimiter" << std::endl;
		return false;
	}
	
	in.read(buf, 4);
	//origX = buf[0]&(buf[1]<<8);
	//origY = buf[2]&(buf[3]<<8);
	
	in.read(buf, 4);
	//width = buf[0]&(buf[1]<<8);
	//height = buf[2]&(buf[3]<<8); // getting the size of the window that we're reading // not used yet
	
	
	if(in.get() != 0x00)
	{
		std::cerr << "Software under developement, \nParameters after the window description not parsed" << std::endl;
		return false;
	}
	
	//uint_8 code_size = 
	in.get();
	
	std::string str = "";

	while((c = in.get())!=0x3b)
	{
		for (int i = 0; i < c; i++) 
			str += char(in.get());
	}
	
	// decode pixels
	{
		istringstream iss(str, istringstream::in);
		ilzwstream lzw(&iss);
		for (int i = 0; i < y_size; i++)
			for (int j = 0; j < x_size; j++)
			{
				std::cout << "toto " << i << " " << j<< std::endl;
				tmp = lzw.get(ch);
				if(tmp==0)
				{
					std::cerr << "File misformed : not enough pixel descriptor" << std::endl;
					return false;
				}
				setPixel(j, i, (uint_8)ch);
				std::cout << "toto " << i << " " << j<< std::endl;
			}
	}
	return true;
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
	for (int i = 0; i < size/BLOCK_SIZE; i++) {
		out.put(BLOCK_SIZE);
		out.write(ptr, BLOCK_SIZE);
		ptr += BLOCK_SIZE;
	}

	// write remaining bytes
	if (size%BLOCK_SIZE != 0) {
		out.put(size%BLOCK_SIZE);
		out.write(ptr, size%BLOCK_SIZE);
	}

	out.put(0x00);
	out.put(0x3b); // GIF file terminator
}

