#include "coding competition common.h"

bool f_AdditionWillOverflow( const t_UnsignedLong p_a, const t_UnsignedLong p_b, const size_t p_numberOfBits )
{
  size_t bit = 0;
  t_UnsignedLong mask = 1;
  bool carry = false;
  t_UnsignedLong result = 0;

  for( ; bit < p_numberOfBits; bit ++, mask <<= 1 )
  {
    unsigned short algorithm = 0;
    bool set_result_bit = false;

    if( p_a & mask )
      algorithm |= 1;
    if( p_b & mask )
      algorithm |= 2;
    if( carry )
      algorithm |= 4;
    switch( algorithm )
    {
      case 0:
        break;
      case 1:
      case 2:
        set_result_bit = true;
        break;
      case 3:
        carry = true;
        break;
      case 4:
        carry = false;
        set_result_bit = true;
        break;
      case 5:
      case 6:
        carry = true;
        break;
      case 7:
        carry = true;
        set_result_bit = true;
        break;
    }
    if( set_result_bit )
      result |= mask;
  }
  return carry;
}