#ifndef EXTRA_H
#define EXTRA_H

typedef unsigned char uint_8;
typedef unsigned int uint_32;

/*
  Writes a gif image to a file

  name : name of the file
  x_size : width of the image
  y_size : height of the image
  img_data : x_size*y_size bytes each describing a pixel
             a pixel is given as a number between 0 and 255 which
	     represents its colour (see col_data)
  col_data : each colour from 0 to 255 given as RGB
             col_data[0] : red   component of colour 0 (0..255)
	     col_data[1] : green component of colour 0 (0..255)
	     col_data[2] : blue  component of colour 0 (0..255)
	     col_data[3] : red   component of colour 1 (0..255)
	     ...
 */
void write_gif(const char *name, 
	       int x_size, 
	       int y_size,
	       char *img_data,
	       char *col_data);

#endif // EXTRA_H
