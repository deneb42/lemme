
#include <iostream>
#include "olzwstream.hpp"

int main()
{
	std::ostream os;
	std::cout << "Compression lzw" << std::endl;
	
	olzwstream ol(&os);
	
	char c[] = "TOBEORNOTTOBEORTOBEORNOT";

	for(int i=0;c[i]!='\0';i++)
		ol.put(c[i]);
	ol.close();
	
	os
	std::cout << std::endl;
	//ol.put('b');
	//std::cout << ol.dictToString();
	
	return 0;
}
