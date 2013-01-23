
#ifndef __LZWSTREAM_BASE_HPP__
#define __LZWSTREAM_BASE_HPP__
	
	#include <string>
	#include "extra.h"
	
	class lzwstream_base
	{
		public:
			virtual void initialize() = 0;
		protected:
			std::string last;
			const int min_code_size = 8,
					  max_code_size = 12;
			int cur_code_size, nb_symbols;
			u_int32 clear_code, end_code, next_code;
	}

#endif // __LZWSTREAM_BASE_HPP__
			
