#include "coding competition common.h"

void p_FreeSubstrings( t_Substrings * const p_substrings, const char * const p_nameOfSubstrings, const char * const p_nameOfFile, const unsigned int p_lineInFile )
{
  if( p_substrings == NULL )
    printf( "Sorry, an error occurred: `%s` is `NULL` on line %u of the file \"%s\".\n", p_nameOfSubstrings, p_lineInFile, p_nameOfFile );
  else
  {
    size_t i = 0;

    for( ; i < p_substrings->m_numberOfSubstrings; i ++ )
      free( p_substrings->m_substrings[ i ] );
    if( p_substrings->m_numberOfSubstrings > 0 )
      free( p_substrings->m_substrings );
    p_substrings->m_numberOfSubstrings = 0;
    p_substrings->m_substrings = NULL;
  }
}
