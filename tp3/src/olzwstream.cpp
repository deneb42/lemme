
#include <string>
#include "olzwstream.hpp"

using namespace std;


olzwstream::olzwstream(std::ostream* strm):obs(strm, 0)
{
	initialize();
	writen=0; read=0;
	write(clear_code());
}


void olzwstream::put(char c)
{
	std::string actual = last;
	read+=8;
	
	actual +=c; // actual is the concatenation of last and the new caracter
	
	if (dict.find(actual)!=dict.end())
		last = actual;
	else
	{	
		write(dict[last]);
		
		dict[actual] = next_code; // insertion of the new tuple
		if (next_code == (1ul << cur_code_size))
		{
			if (cur_code_size == max_code_size)
			{
				write(clear_code());
				initialize();
			}
			else
			{
				next_code++;
				cur_code_size++;
				obs.setLength(cur_code_size);
			}
		}
		else
			next_code++;
			
		last.clear();
		last += c;
	}
}

void olzwstream::close()
{
	if(!last.empty())
		write(dict[last]);
	write(end_code());
	obs.flush();
	std::cout << read/8 << " bytes lus." << std::endl
			  << writen/8 << " bytes ecris." << std::endl;
}

void olzwstream::initialize()
{
	dict.clear();
	last.clear(); 

	for(unsigned int i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<std::string, uint_32>(std::string(1, char(i)), i));

	cur_code_size = min_code_size+1;
	obs.setLength(cur_code_size);
	next_code = nb_symbols+2;
}

void olzwstream::write(uint_32 c)
{
	obs.put(c);
	writen+=cur_code_size;

}

std::string olzwstream::dictToString()
{
	std::string str("");
	for(std::map<std::string, uint_32>::const_iterator it=dict.begin();it!=dict.end();it++)
	{	
		if(it->second > 255)
			str += "<" + to_string(it->second) + ">\t"+ it->first + "\n";
	}
	return str;
}
