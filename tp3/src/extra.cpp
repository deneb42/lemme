#include "extra.h"
#include <fstream>
#include <sstream>
#include "olzwstream.hpp"

const uint_8 BLOCK_SIZE = 255;

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

void write_gif(const char *name, 
	       int x_size, 
	       int y_size,
	       char *img_data,
	       char *col_data) {
  uint_8 header[13] = 
    { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61, // GIF89a
      (uint_8)(x_size&0xff), (uint_8)(x_size>>8), // width
      (uint_8)(y_size&0xff), (uint_8)(y_size>>8), // height
      GLOBAL_COLOR_TABLE_FLAG | // use global color table
      COLOR_RESOLUTION_8_BIT |  // use 8 bit per R/G/B
      SIZE_OF_GLOBAL_COLOR_TABLE_256, // use 256 colours
      0x00, // default background colour
      0x00 };
      
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
    for (int i = 0; i < x_size*y_size; i++) 
      lzw.put(img_data[i]);
    lzw.close();
      std::cout << "taille de l'image non compressee : " << x_size*y_size*3 << " bytes" << std::endl;
	  std::cout << "taille de l'image     compressee : " << lzw.getWriten()/8 << " bytes" << std::endl;
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
