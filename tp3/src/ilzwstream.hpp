
#ifndef __ILZWSTREAM_HPP__
#define __ILZWSTREAM_HPP__
	
	#include <iostream>
	
	class ilzwstream : lzwstream_base
	{
		public:
			ilzwstream(istream* ptr);
			
			void read_to_buffer();
			int get(char& c);
			bool eof();
			
			void initialize();
		private:
			std::vector<u_int32, vector<char> > dict;
	}
			
			
