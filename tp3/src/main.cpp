
#include <iostream>
#include <fstream>
#include "olzwstream.hpp"
#include "ilzwstream.hpp"
#include "mandelbrot.hpp"

using namespace std;

int main()
{
	int i;
	std::cout << "Compression lzw" << std::endl;

	
	//char c[] = "TOBEORNOTTOBEORTOBEORNOT";
	char c[] = "Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean Jean ";
	
	{
		ofstream toto ("test.txt", fstream::out);
		olzwstream ol(&toto);
		for(i=0;c[i]!='\0';i++)
			ol.put(c[i]);
		ol.close();
	
	std::cout << "Compression terminee, "<< i*8 << "bits => " << ol.getWriten() << "bits." << std::endl;
}

{
		std::cout << "Decompression lzw" << std::endl;
		ifstream toto2 ("test.txt", fstream::in);
		ilzwstream il(&toto2);

	while(!il.eof())
	//for(int i=0;i<10;i++)
	{
		//std::cout << "toto" << std::endl;
		char tmp;
		if(il.get(tmp)!=0)
			std::cout << tmp; // << std::endl;
	}
	cout << std::endl;
	//cout << std::endl << il.dictToString();
	}
	
	//write_mandel("toto.gif", 400, 200);
	
	std::cout << "Decompression terminee" << std::endl;
	return 0;
}
