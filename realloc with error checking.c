#include "coding competition common.h"

void *f_realloc_WithErrorChecking( void *p_originalMemory, const size_t p_sizeInBytes, const char * const p_nameOfPointer, const char * const p_nameOfFile, const unsigned int p_lineInFile )
{
  void *memory = realloc( p_originalMemory, p_sizeInBytes );

  if( memory == NULL )
  {
    printf( "Sorry, an error occurred: memory ("  );
    printf( k_UnsignedLong_printf_Format, ( t_UnsignedLong_printf_Typecast )p_sizeInBytes );
    printf( " bytes) for `%s` wasn't able to be re-allocated on line %u of the file \"%s\".\n", p_nameOfPointer, p_lineInFile, p_nameOfFile );
    p_Exit( EXIT_FAILURE );
  }
  return memory;
}