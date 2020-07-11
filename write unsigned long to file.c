#include "coding competition common.h"

void p_WriteUnsignedLongToFile( FILE * const p_file, const t_UnsignedLong p_unsignedLong )
{
  fprintf( p_file, k_UnsignedLong_printf_Format, ( t_UnsignedLong_printf_Typecast )p_unsignedLong );
}