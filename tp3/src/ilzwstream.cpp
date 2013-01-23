
#include <iostream>
#include "ilzwstream.hpp"


ilzwstream::ilzwstream(std::istream* strm):is(strm)
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

void ilzwstream::initialize()
{
	dict.clear();
	last.clear();
	dict.insert(std::pair<uint_32, std::vector<char> >(clear_code, std::vector<char>()));

	for(char i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<uint_32, std::vector<char> >(i, std::vector<char>(i)));
	
	next_code = nb_symbols+2;
	cur_code_size = min_code_size+1;
}
