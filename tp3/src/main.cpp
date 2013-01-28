
#include <iostream>
#include "olzwstream.hpp"
#include "mandelbrot.hpp"

int main()
{
	std::cout << "Compression lzw" << std::endl;
	
	/*
	olzwstream ol(&std::cout);
	
	char c[] = "TOBEORNOTTOBEORTOBEORNOT";
	
	for(int i=0;c[i]!='\0';i++)
		ol.put(c[i]);
	ol.close();
	
	//os
	std::cout << std::endl;
	//ol.put('b');
	//std::cout << ol.dictToString();
	*/
	write_mandel("toto.gif", 400, 400);
	
	return 0;
}
