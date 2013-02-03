#include "obitstream.h"


/* Constructor */
obitstream::obitstream(std::ostream* strm, int len)
  : strm(strm), bitlen(len), buffer(0), bufpos(0), status(0)
{
}

/* Write bits to stream */
void obitstream::put(uint_32 bits) 
{
  // check status
  if (!(*this)) {
    return;
  }

  // add bits to the buffer
  buffer |= (bits << bufpos);
  bufpos += this->getLength();

  // write characters from the buffer to the stream, if possible
  while (bufpos >= 8) {
    unsigned char c = buffer & 0xff;
    strm->put(c);

    // remove bits from buffer and adjust bufpos
    buffer = buffer >> 8;
    bufpos -= 8;
  }
}

/* Write bits to stream */
obitstream& obitstream::operator<<(uint_32 bits)
{
  this->put(bits);
  return *this;
}

/* Test whether the internal buffer is empty */
bool obitstream::bufferEmpty() const
{
  return bufpos == 0;
}

/* Write out the internal buffer to the ostream */
void obitstream::flush() {

  // write remaining bytes
  while (bufpos >= 8) {
    char c = buffer & 0xff;
    strm->put(c);
    bufpos -= 8;
    buffer = buffer >> 8;
  }

  // write final bits padded with 0s to a byte
  if (bufpos != 0) {
    char c = buffer;
    strm->put(c);
    bufpos = 0;
    buffer = 0;
  }

}

/* Set the current number of bits extracted from the stream */
void obitstream::setLength(int len)
{
  bitlen = len;
}

/* Get the current number of bits extracted from the stream */
int obitstream::getLength() const
{ 
  return bitlen;
}

/* Test the bitstream */
bool obitstream::operator!() const
{
  return !this->good();
}

/* End of file */
bool obitstream::eof() const
{
  return status != 0;
}

/* Test the bitstream */
bool obitstream::good() const
{
  return status == 0;
}
