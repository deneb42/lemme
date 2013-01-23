
#include <iostream>
#include "olzwstream.hpp"

int main()
{
	std::cout << "Compression lzw" << std::endl;
	
	olzwstream ol(NULL);
	
	ol.put('a');
	
	return 0;
}
