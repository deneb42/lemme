
#include "olzwstream.hpp"

using namespace std;


olzwstream::olzwstream(std::ostream* strm):os(strm)
{
	initialize();
}

void olzwstream::put(char c)
{
	vector<char> actual = last.push_back(c);
	
	
	if (dict.find(actual)) {
		last = actual;
	}
	else
	{
		cout << "last: " << last << " code word: " << dict[last] << endl;
		dict[actual] = next_code;
		if (next_code == (1ul << cur_code_size))
		{
			if (cur_code_size == max_code_size)
			{
				cout << "clear code: " << clear_code << endl;
				initialize();
			}
			else
			{
				next_code += 1;
				cur_code_size += 1;
			}
		}
		last.clear();
		last.push_back(c);
		
	}
	
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
