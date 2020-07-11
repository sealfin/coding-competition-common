#include "coding competition common.h"

/* The following function will return `true` (and store the result in `p_a`) if `p_a` and `p_b` were able to be multiplied together without overflow occurring, and will return `false` (and `p_a` will not be changed) if `p_a` and `p_b` were not able to be multiplied together without overflow occurring. */
static bool f_MultiplyUnsignedLongs( t_UnsignedLong * const p_a, const t_UnsignedLong p_b )
{
  t_UnsignedLong a, k, b;

  if( *p_a > p_b )
  {
    a = k = *p_a;
    b = p_b;
  }
  else
  {
    a = k = p_b;
    b = *p_a;
  }
  if(( a == 0 ) || ( b == 0 ))
    a = 0;
  else
    for( ; b > 1; b -- )
    {
      if( M_AdditionWillOverflow( a, k ))
        return false;
      a += k;
    }
  *p_a = a;
  return true;
}

t_StringToUnsignedLongError f_StringToUnsignedLong( const char * const p_string, t_UnsignedLong * const p_unsignedLong )
{
  size_t i;
  bool first_loop = true;
  t_UnsignedLong multiplier = 1, value_to_assign, value = 0;

  if( p_string == NULL )
    return k_StringToUnsignedLongError_p_string_Is_NULL;
  i = strlen( p_string );
  if( i == 0 )
    return k_StringToUnsignedLongError_p_string_IsZeroCharactersInLength;
  for( ; i > 0; i -- )
  {
    const char digit = p_string[ i - 1 ];

    if(( digit >= '0' ) && ( digit <= '9' ))
    {
      if( !first_loop )
        if( !f_MultiplyUnsignedLongs( &multiplier, 10 ))
          return k_StringToUnsignedLongError_multiplier_Overflowed;
      value_to_assign = multiplier;
      if( !f_MultiplyUnsignedLongs( &value_to_assign, digit - '0' ))
        return k_StringToUnsignedLongError_value_to_assign_Overflowed;
      if( M_AdditionWillOverflow( value, value_to_assign ))
        return k_StringToUnsignedLongError_value_Overflowed;
      value += value_to_assign;
      first_loop = false;
    }
    else
      return k_StringToUnsignedLongError_p_string_ContainsANonDigitCharacter;
  }
  *p_unsignedLong = value;
  return k_StringToUnsignedLongError_None;
}