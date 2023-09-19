#include "coding competition common.h"

char *f_TrimString( const char * const p_string, const char * const p_nameOfString, const char * const p_nameOfFile, const unsigned int p_lineInFile )
{
  if( p_string == NULL )
  {
    printf( "Sorry, a warning occurred: `%s` is `NULL` on line %u of the file \"%s\".\n", p_nameOfString, p_lineInFile, p_nameOfFile );
    return NULL;
  }
  else
  {
    size_t i = 0, k = strlen( p_string ), string_length;
    char *string;
    size_t m = 0;

    for( ; i < k; i ++ )
      if( isgraph( p_string[ i ] ))
        break;

    for( ; k > i; k -- )
      if( isgraph( p_string[ k - 1 ] ))
      {
        k --;
        break;
      }

    string_length = k - i + (( isgraph( p_string[ i ] ))?1:0 );
    string = ( char* )M_malloc_WithErrorChecking( sizeof( char ) * ( string_length + 1 ), "string" );
    if( isgraph( p_string[ i ] ))
      for( ; i <= k; i ++, m ++ )
        string[ m ] = p_string[ i ];
    string[ m ] = '\0';
    return string;
  }
}