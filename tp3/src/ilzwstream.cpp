
#include <iostream>
#include "ilzwstream.hpp"


ilzwstream::ilzwstream(std::istream* strm):ibs(strm)
{
	initialize();
}
			
void ilzwstream::read_to_buffer()
{
	
}

int ilzwstream::get(char& c)
{
	return c;
}

bool ilzwstream::eof()
{
	return true;
}

uint_32 ilzwstream::read()
{
	uint32 c = ibs.read();
	
	if(VERBOSE)
		std::cout << " Read code word: " << c;
}

void ilzwstream::initialize()
{
	dict.clear();
	last.clear();

	for(unsigned int i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<uint_32, std::vector<char> >(i, std::vector<char>(1, i)));
	
	cur_code_size = min_code_size+1;
	ibs.setLength(cur_code_size);
	next_code = nb_symbols+2;
}

std::string ilzwstream::dictToString()
{
	std::string str("");
	for(std::map<uint_32, std::vector<char>>::const_iterator it=dict.begin();it!=dict.end();it++)
	{	
		for(std::vector<char>::const_iterator it2=it->first.begin();it2!=it->first.end();it2++)
			str+= (*it2);
		str+= "\t<" + to_string(it->second) + ">\n";
	}
	return str;
}
