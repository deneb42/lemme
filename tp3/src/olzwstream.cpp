#include "olzwstream.hpp"

using namespace std;

olzwstream::olzwstream(std::ostream* strm)
{
	
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

	
}
