
#include <iostream>
#include <string>
#include "ilzwstream.hpp"
#include "ibitstream.h"


ilzwstream::ilzwstream(std::istream* strm):ibs(strm, 0)
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

uint_32 ilzwstream::read()
{
	uint_32 c;
	ibs.get(c);
	
	if(VERBOSE)
		std::cout << " Read code word: " << c;
	return c;
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
		for(std::vector<char>::const_iterator it2=it->second.begin();it2!=it->second.end();it2++)
			str+= (*it2);
		str+= "\t<" + std::to_string(it->first) + ">\n";
	}
	return str;
}
