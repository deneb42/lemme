#include <fstream>
#include <complex>
#include <vector>

#include "extra.h"
#include "mandelbrot.hpp"

using namespace std;

const complex<double> c1(-2,-1);
const complex<double> c2(1,1);

void write_mandel(std::string name, int x, int y)
{
  
  char col[256*3];
  std::vector<char> data;
  
  for(int i=0; i<256;i++)
  {
	  col[3*i]=i;
	  col[3*i+1]=i;
	  col[3*i+2]=i; // initialisation des couleurs (nuances de gris)
  }
  
  data.resize(y*x);

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
      data[i*x+j] = MAX_ITER-iter;
    }
  }
  write_gif(name.c_str(), x, y, data.data(), col);
}
