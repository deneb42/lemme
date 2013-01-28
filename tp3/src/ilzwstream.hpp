
#ifndef __ILZWSTREAM_HPP__
#define __ILZWSTREAM_HPP__
	
	#include <iostream>
	#include <vector>
	#include <map>
	#include <list>
	#include "lzwstream_base.hpp"
	#include "ibitstream.h"
	
	
	class ilzwstream : lzwstream_base
	{
		public:
			ilzwstream(std::istream* strm);
			
			void read_to_buffer();
			int get(char& c);
			bool eof();
			uint_32 read();
			
			std::string dictToString();
			void initialize();
		private:
			//std::istream* is;
			ibitstream ibs;
			std::map<uint_32, std::vector<char> > dict;
			bool _eof;
			std::list<char> buffer;
	};
			
#endif // __ILZWSTREAM_HPP__	
