
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

olzwstream::olzwstream(std::ostream* strm):obs(strm, 0)
{
	initialize();
	writen=0; read=0;
	write(clear_code());
}

//olzwstream::~olzwstream() {
//}

void olzwstream::put(char c)
{
	std::string actual = last;
	read+=8;
	
	actual +=c; // actual is the concatenation of last and the new caracter
	/*	
	if(VERBOSE>1)
	{	cout << "last: ";
		for(vector<char>::const_iterator it=last.begin(); it!=last.end();it++)
			cout << *it;
		cout << endl << "actual: ";
		for(vector<char>::const_iterator it=actual.begin(); it!=actual.end();it++)
			cout << *it;
		cout << endl;
	}*/
	
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
				//cout << "inc " << endl;
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
	//std::cout << dictToString();
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
	
	if(VERBOSE)
	{
		std::cout << " code word: " << c << " Meaning : ";
		if(c==clear_code())
			std::cout << "clear_code";
		else if(c==end_code())
			std::cout << "end_code";
		else
			std::cout << last;
		std::cout << std::endl;
	}
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
