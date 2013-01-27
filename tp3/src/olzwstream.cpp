
#include <string>
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

olzwstream::~olzwstream() {
	if(!last.empty())
		cout << " code word: " << dict[last]  << "Meaning : ";
	for(vector<char>::const_iterator it=last.begin(); it!=last.end();it++)
			cout << *it;
	cout << endl;
}

void olzwstream::put(char c)
{
	vector<char> actual = last;
	actual.push_back(c); // actual is the concatenation of last and the new caracter
		
	if(VERBOSE>1)
	{	cout << "last: ";
		for(vector<char>::const_iterator it=last.begin(); it!=last.end();it++)
			cout << *it;
		cout << endl << "actual: ";
		for(vector<char>::const_iterator it=actual.begin(); it!=actual.end();it++)
			cout << *it;
		cout << endl;
	}
	
	if (contains(dict, actual)) {
		last = actual;
	}
	else
	{
		if(VERBOSE>1)
		{
			cout << "last: ";
			for(vector<char>::const_iterator it=last.begin(); it!=last.end();it++)
				cout << *it;
		}
		
		cout << " code word: " << dict[last]  << "Meaning : ";
		for(vector<char>::const_iterator it=last.begin(); it!=last.end();it++)
				cout << *it;
		cout << endl;
		dict[actual] = next_code; // insertion of the new tuple
		if (next_code == (1ul << cur_code_size))
		{
			if (cur_code_size == max_code_size)
			{
				cout << "clear code: " << clear_code() << endl;
				initialize();
			}
			else
			{
				next_code++;
				cur_code_size++;
				cout << "inc " << endl;
			}
		}
		else
			next_code++;
			
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
}

std::string olzwstream::dictToString()
{
	std::string str("");
	for(std::map<std::vector<char>, uint_32>::const_iterator it=dict.begin();it!=dict.end();it++)
	{	
		str += "<" + to_string(it->second) + ">\t";
		for(std::vector<char>::const_iterator it2=it->first.begin();it2!=it->first.end();it2++)
			str+= (*it2);
		str+= "\n";
	}
	return str;
}
