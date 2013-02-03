#include <fstream>
#include <complex>
#include <vector>

#include "mandelbrot.hpp"
#include "GIF_image.hpp"

using namespace std;

const complex<double> c1(-2,-1);
const complex<double> c2(-0.5, -0.3);

void write_mandel(std::string name, int x, int y)
{
  GIF_image gif(x, y);
  
  for(int i=0; i<256;i++)
  {
	  gif.setColor(i, i, i, (char)255);
  }

  for (int i = 0; i < y; i++) 
  { 
    for (int j = 0; j < x; j++) 
    {
      complex<double> c(c1.real()+j*(c2-c1).real()/X, c1.imag()+i*(c2-c1).imag()/Y);
      complex<double> z = 0;
      int iter = 0;
      
      while (abs(z) < 2 && iter < MAX_ITER) 
      {
		z = z*z+c;
		iter++;
      }
      gif.setPixel(j, i, ((MAX_ITER-iter)*255)/40);
    }
  }
  
  gif.writeToFile(name.c_str());
}
