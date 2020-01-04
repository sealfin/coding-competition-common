#include "coding competition common.h"

t_StringToUnsignedIntError f_StringToUnsignedInt( const char * const p_string, unsigned int * const p_unsignedInt )
{
  size_t i;
  t_UnsignedLong multiplier = 1, value = 0;

  if( p_string == NULL )
    return k_StringToUnsignedIntError_p_string_Is_NULL;
  i = strlen( p_string );
  if( i == 0 )
    return k_StringToUnsignedIntError_p_string_IsZeroCharactersInLength;
  for( ; i > 0; i --, multiplier *= 10 )
  {
    const char digit = p_string[ i - 1 ];

    if(( digit >= '0' ) && ( digit <= '9' ))
    {
      if( multiplier > UINT_MAX )
        return k_StringToUnsignedIntError_multiplier_IsGreaterThan_UINT_MAX;
      value += (( digit - '0' ) * multiplier );
      if( value > UINT_MAX )
        return k_StringToUnsignedIntError_value_IsGreaterThan_UINT_MAX;
    }
    else
      return k_StringToUnsignedIntError_p_string_ContainsANonDigitCharacter;
  }
  *p_unsignedInt = value;
  return k_StringToUnsignedIntError_None;
}