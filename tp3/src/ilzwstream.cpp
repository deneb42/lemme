
#include <iostream>
#include "ilzwstream.hpp"

ilzwstream::ilzwstream(std::istream* strm):is(strm)
{
	initialize();
}
			
void ilzwstream::read_to_buffer()
{
	uint_32 cw = read();
	std::vector<char> = str;
	
	if (cw == clear_code())
	{
		initialize(); //last.clear() fait par initialise()
		cw = read();
	}
	if (cw == end_code())
	{
		_eof = true;
		return ;
	}
	if (dict.find(cw)) {
		
	}
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
	dict.insert(std::pair<uint_32, std::vector<char> >(clear_code(), std::vector<char>()));

	for(unsigned int i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<uint_32, std::vector<char> >(i, std::vector<char>(1, i)));
	
	cur_code_size = min_code_size+1;
	next_code = nb_symbols+2;
}
