#include "olzwstream.hpp"

olzwstream::olzwstream(std::ostream* strm):os(strm)
{
	initialize();
}

void olzwstream::put(char c)
{
	
}

void olzwstream::close()
{
	
}

void olzwstream::initialize()
{
	dict.clear();
	last.clear();
	dict.insert(std::pair<std::vector<char>, uint_32>(std::vector<char>(), clear_code));

	for(char i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<std::vector<char>, uint_32>(std::vector<char>(i), i));
	
	next_code = nb_symbols+2;
	cur_code_size = min_code_size+1;
}
