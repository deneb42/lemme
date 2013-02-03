
#include <iostream>
#include <string>
#include "ilzwstream.hpp"
#include "ibitstream.h"

using namespace std;

ilzwstream::ilzwstream(std::istream* strm):ibs(strm, 0)
{
	_eof = false;
	initialize();
}
			
void ilzwstream::read_to_buffer()
{
	uint_32 cw = read();
	std::string str;
	
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
	if (dict.find(cw) != dict.end()) 
	{
		str = dict[cw];
	}
	else
	{
		str = last + last[0];
	}
	if(!str.empty())
		for (std::string::iterator it = str.begin(); it != str.end(); it ++) {
			buffer.push_back(*it);
		}
	if (!last.empty()) {
		dict[next_code] = last + str[0];
		next_code++;
		
		if (next_code == 1ul << cur_code_size) {
			if (cur_code_size < max_code_size) {
				cur_code_size++;
				ibs.setLength(cur_code_size);
			}
		}
	}
	last = str;
	
}

int ilzwstream::get(char& c)
{
	if(buffer.empty() && !_eof)
		read_to_buffer();
		
	if(buffer.empty())
	{
		_eof = true;
		return 0;
	}
	else
	{
		c = buffer.front();
		buffer.pop_front();
		return 1;
	}
}

bool ilzwstream::eof()
{
	return _eof;
}

uint_32 ilzwstream::read()
{
	uint_32 c;
	ibs.get(c);
	
	if(VERBOSE)
		std::cout << " Read code word: " << c << std::endl;
	return c;
}

void ilzwstream::initialize()
{
	dict.clear();
	last.clear();

	for(unsigned int i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<uint_32, std::string >(i, std::string(1, char(i))));
	
	cur_code_size = min_code_size+1;
	ibs.setLength(cur_code_size);
	next_code = nb_symbols+2;
}

std::string ilzwstream::dictToString()
{
	std::string str("");
	for(std::map<uint_32, std::string>::const_iterator it=dict.begin();it!=dict.end();it++)
	{	
		str+= it->second + "\t<" + std::to_string(it->first) + ">\n";
	}
	return str;
}
