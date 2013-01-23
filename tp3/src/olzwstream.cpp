
#include "olzwstream.hpp"

using namespace std;


bool toto(const std::vector<char> v1, const std::vector<char> v2)
{
	if(v1.size() != v2.size())
		return false;
	for(unsigned int i=0;i<v1.size();i++)
		if(v1[i]!=v2[i])
			return false;
	return true;
}

bool contains(const std::map<std::vector<char>, uint_32> &d, const std::vector<char> &a)
{
	for(std::map<std::vector<char>, uint_32>::const_iterator it=d.begin();it!=d.end();it++)
	{
		if(toto(it->first, a))
			return true;
	}
	return false;
}

olzwstream::olzwstream(std::ostream* strm):os(strm)
{
	initialize();
}

void olzwstream::put(char c)
{
	vector<char> actual = last;
	actual.push_back(c);
	
	
	if (contains(dict, actual)) {
		last = actual;
		//cout << "lulz "  << endl;
	}
	else
	{
		cout << "last: ";
		for(vector<char>::const_iterator it=last.begin(); it!=last.end();it++)
			cout << *it;
		cout << " code word: " << dict[last] << endl;
		dict[actual] = next_code;
		if (next_code == (1ul << cur_code_size))
		{
			if (cur_code_size == max_code_size)
			{
				cout << "clear code: " << clear_code() << endl;
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
	dict.insert(std::pair<std::vector<char>, uint_32>(std::vector<char>(), clear_code()));

	for(unsigned int i=0;i<nb_symbols;i++) // initializing the first caracters
		dict.insert(std::pair<std::vector<char>, uint_32>(std::vector<char>(1, i), i));

	cur_code_size = min_code_size+1;
	next_code = nb_symbols+2;
	
	if(VERBOSE)
		for(std::map<std::vector<char>, uint_32>::const_iterator it=dict.begin();it!=dict.end();it++)
			{for(std::vector<char>::const_iterator it2=it->first.begin();it2!=it->first.end();it2++)
				cout << (*it2);
			cout << " val : " << it->second << endl;
		}
}
