
#include <iostream>
#include "olzwstream.hpp"

int main()
{
	std::cout << "Compression lzw" << std::endl;
	
	olzwstream ol(NULL);
	
	char c[] = "TOBEORNOTTOBEORTOBEORNOT";

	for(int i=0;c[i]!='\0';i++)
		ol.put(c[i]);
	ol.close();
	//ol.put('b');
	//std::cout << ol.dictToString();
	
	return 0;
}
