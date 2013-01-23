
#include <iostream>
#include "olzwstream.hpp"

int main()
{
	std::cout << "coucou" << std::endl;
	
	olzwstream ol(NULL);
	
	ol.put('a');
	
	return 0;
}
