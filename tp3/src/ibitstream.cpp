#include "ibitstream.h"

/* Constructor */
ibitstream::ibitstream(std::istream* strm, int len)
  : strm(strm), bitlen(len), buffer(0), bufpos(0), status(0) {}

/* Get bits from stream
   returns the number of bits read */
int ibitstream::get(uint_32& bits)
 {
  // check status
  if (!(*this)) {
    return 0;
  }

  while (strm->good() && bufpos < this->getLength()) {
    char c;
    strm->get(c);
    uint_32 byte = (unsigned char)c;
    buffer |= (byte << bufpos);
    bufpos += 8;
  }

  int extracted = (bufpos < this->getLength()) ? bufpos : this->getLength();

  bits = buffer & ((1ul << extracted)-1);

  // remove bits from buffer and adjust bufpos
  buffer = buffer >> extracted;
  bufpos -= extracted;

  // if end of file, then change status
  if (!strm->good() || strm->peek() == std::istream::traits_type::eof())
    status = 1;

  // not correct!
  return extracted;
}

/* Get bits from stream */ 
ibitstream& ibitstream::operator>>(uint_32& bits)
{
  this->get(bits);
  return *this;
}

/* Set the current number of bits extracted from the stream */
void ibitstream::setLength(int len)
{
  bitlen = len;
}

/* Get the current number of bits extracted from the stream */
int ibitstream::getLength() const
{ 
  return bitlen;
}

/* Test the bitstream */
bool ibitstream::operator!() const
{ 
  return !this->good();
}

/* End of file */
bool ibitstream::eof() const
{
  return status == 1 && bufpos == 0;
}

/* Test the bitstream */
bool ibitstream::good() const
{
  return !this->eof();
}
