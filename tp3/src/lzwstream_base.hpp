
#ifndef __LZWSTREAM_BASE_HPP__
#define __LZWSTREAM_BASE_HPP__
	
	#include <vector>
	#include "extra.h"
	
	class lzwstream_base
	{
		public:
			virtual void initialize() = 0;
			
			uint_32 clear_code() { return cc;}
			uint_32 end_code() { return ec;}
		protected:
			static const int min_code_size = 8,
							 max_code_size = 12;
			static const uint_32 nb_symbols = 1ul<<min_code_size; 
			static const uint_32 cc = nb_symbols;
			static const uint_32 ec = nb_symbols+1;
			
			std::vector<char> last;
			int cur_code_size; 
			uint_32 next_code;
	};

#endif // __LZWSTREAM_BASE_HPP__
			
