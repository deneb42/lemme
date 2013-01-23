
#ifndef OLZWSTREAM_H
#define OLZWSTREAM_H

#include <iostream>

#include <map>
#include "lzwstream_base.hpp"

	class Olzwstream : lzwstream_base
	{
		public:
			Olzwstream(std::ostream* strm);//constructeur par défaut
			void put(char c); // takes an input byte and writes some encoded data to stream.
			void close(); //terminates the encoding
		
		private:
			std::map<std::vector<char>, uint_32> dict;
			



#endif // OLZWSTREAM_H