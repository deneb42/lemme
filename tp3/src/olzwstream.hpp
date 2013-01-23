
#ifndef OLZWSTREAM_H
#define OLZWSTREAM_H

#include <iostream>
#include "ilzwstream_base.hpp"

	class Olzwstream : ilzwstream_base
	{
		public:
		Olzwstream(std::ostream-pointer strm){};//constructeur par défaut
		void put(char c); // takes an input byte and writes some encoded data to stream.
		void close(); //terminates the encoding
		
		private:




#endif // OLZWSTREAM_H