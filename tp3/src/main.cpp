
#include <iostream>
#include <fstream>
#include "olzwstream.hpp"
#include "ilzwstream.hpp"
#include "mandelbrot.hpp"
#include "GIF_image.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	std::ifstream in;
	std::ofstream out;
	char c;
	
	if(argc>=3)
	{		
		if(argv[1][0]=='c')
		{
			in.open(argv[2], fstream::in);
			out.open((argc>3?argv[3]:"out.lzw"), fstream::out);

			std::cout << "Compression lzw" << std::endl;
			olzwstream ol(&out);
			
			while(!in.eof())
			{
				c = (char)in.get();
				if(!in.eof())
					ol.put(c);
			}
			ol.close();
			std::cout << "Compression terminee" << std::endl;
		}
		else if(argv[1][0]=='d')
		{
			in.open(argv[2], fstream::in);
			out.open((argc>3?argv[3]:"out"), fstream::out);
			
			std::cout << "Decompression lzw" << std::endl;
			ilzwstream il(&in);

			while(!il.eof())
			{
				if(il.get(c)!=0)
					out.put(c);
			}
			std::cout << "Decompression terminee" << std::endl;
		}
		else if(argv[1][0]=='r')
		{
			GIF_image gif;
			gif.readFromFile(argv[2]);
			gif.stamp();
			gif.writeToFile((argc>3?argv[3]:"read.gif"));
		}
		else
			write_mandel("../data/mandel.gif", 1500, 1500);
	}
	else
		write_mandel("../data/mandel.gif", 1500,1500);

	return 0;
}
