
#ifndef OLZWSTREAM_H
#define OLZWSTREAM_H

	#include <iostream>
	#include <map>
	#include <vector>
	#include <string>
	#include "extra.h"
	#include "lzwstream_base.hpp"
	#include "obitstream.h"

	class olzwstream : lzwstream_base
	{
		public:
			olzwstream(std::ostream* strm);//constructeur
			//~olzwstream();

			void put(char c); // takes an input byte and writes some encoded data to stream.
			void close(); //terminates the encoding
			void initialize();
			void write(uint_32 c);
			int getWriten() {return writen;}
			
			std::string dictToString();
		private:
			//std::ostream* os;
			int writen;
			obitstream obs;
			std::map<std::vector<char>, uint_32> dict;
	};
			
#endif // OLZWSTREAM_H
