#ifndef OBITSTREAM_H
#define OBITSTREAM_H

#include <ostream>
#include "extra.h"

/*
  A wrapper for an ostream that allows the user to write a selected number of
  bits at a time

  Example:

  ostringstream s;
  obitstream bs(&s,4);

  string str = "Bonjour";
  for (size_t pos = 0; pos < str.size(); pos++) {
    bs.put(str.at(pos) & 0xf); bs.put(str.at(pos) >> 4);
  }
  cout << s.str() << endl;
*/
class obitstream {
private:
  
  /* The associated stream */
  std::ostream* strm;
  /* The current number of bits to be written */
  int bitlen;

  /* A buffer holding partial bytes for the stream */
  uint_32 buffer;
  /* Current number of bits in the buffer */
  int bufpos;

  /* The status of the bitstream, 0 = ok, 1 = not ok */
  int status;

public:
  obitstream(std::ostream* strm, int len = 8);
  
  /* Write bits to stream */
  void put(uint_32 bits);
  /* Write bits to stream */
  obitstream& operator<<(uint_32 bits);

  /* Test whether the internal buffer is empty */
  bool bufferEmpty() const;
  /* Write out the internal buffer to the ostream */
  void flush();

  /* Set the current number of bits extracted from the stream */
  void setLength(int len);
  /* Get the current number of bits extracted from the stream */
  int getLength() const;

  /* Test the bitstream */
  bool operator!() const;
  /* End of file */
  bool eof() const;
  /* Test the bitstream */
  bool good() const;

};

#endif // OBITSTREAM_H
