
#ifndef __MANDELBROT_HPP__
#define __MANDELBROT_HPP__

	#include <string>
	#include "extra.h"
	
	#define X 720
	#define Y 480

	#define MAX_ITER 40
	
	void write_mandel(std::string name, int x=X, int y=Y);
			
#endif // __MANDELBROT_HPP__
