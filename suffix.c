#include "coding competition common.h"

const char * const f_Suffix( const unsigned int p )
{
  const char *suffix = "th";

  switch( p % 10 )
  {
    case 1:
      if( p % 100 != 11 )
        suffix = "st";
      break;
    case 2:
      if( p % 100 != 12 )
        suffix = "nd";
      break;
    case 3:
      if( p % 100 != 13 )
        suffix = "rd";
  }
  return suffix;
}
