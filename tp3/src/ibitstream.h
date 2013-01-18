#ifndef IBITSTREAM_H
#define IBITSTREAM_H

#include <istream>
#include "extra.h"

/*
  A wrapper for an istream that allows the user to extract a selected number of
  bits at a time

  Example:

  istringstream s("abc");
  ibitstream bs(&s,8);

  uint_32 bits;
  while (bs.good()) {
    bs.get(bits); cout << bits << " ";
  }
  cout << endl;
*/
class ibitstream {
private:
  
  /* The associated stream */
  std::istream* strm;
  /* The current number of bits to be extracted */
  int bitlen;

  /* A buffer holding partial bytes from the stream */
  uint_32 buffer;
  /* Current number of bits in the buffer */
  int bufpos;

  /* The status of the bitstream, 0 = ok, 1 = eof */
  int status;

public:
  ibitstream(std::istream* strm, int len = 8) ;
  
  /* Get bits from stream 
     returns the number of bits read */
  int get(uint_32& bits);
  /* Get bits from stream */
  ibitstream& operator>>(uint_32& bits);

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

#endif // IBITSTREAM_H
