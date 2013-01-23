
#ifndef __ILZWSTREAM_HPP__
#define __ILZWSTREAM_HPP__
	
	#include <iostream>
	#include <vector>
	#include <map>
	#include "lzwstream_base.hpp"
	
	
	class ilzwstream : lzwstream_base
	{
		public:
			ilzwstream(std::istream* ptr);
			
			void read_to_buffer();
			int get(char& c);
			bool eof();
			
			void initialize();
		private:
			std::istream* is;
			std::map<u_int32, std::vector<char> > dict;
	}
			
#endif // __ILZWSTREAM_HPP__	
