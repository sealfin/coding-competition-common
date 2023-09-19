#include "coding competition common.h"

static t_SplitStringDecision f_SplitStringDecision( char p_character, void *p_data )
{
  const char character =
  #if defined( LEONARDO ) || defined( __MWERKS__ )
  ':'
  #else
  '/'
  #endif
  ;

  if( p_character != character )
    return k_SplitStringDecision_RetainCharacter;
  else
    return k_SplitStringDecision_EndSubstring;
}

char *f_GetNameOfFileFromPath( const char * const p_pathToFile, const char * const p_nameOfPathToFile, const char * const p_nameOfFile, const unsigned int p_lineInFile )
{
  char *name_of_file = NULL;

  if( p_pathToFile == NULL )
    printf( "Sorry, a warning occurred: `p_pathToFile` (`%s`) is `NULL` on line %u of the file \"%s\".\n", p_nameOfPathToFile, p_lineInFile, p_nameOfFile );
  else
  {
    t_Substrings substrings = M_SplitString( p_pathToFile, f_SplitStringDecision, NULL );
    const char * const substring = substrings.m_substrings[ substrings.m_numberOfSubstrings - 1 ];
    name_of_file = ( char* )M_malloc_WithErrorChecking( sizeof( char ) * ( strlen( substring ) + 1 ), "name_of_file" );

    strcpy( name_of_file, substring );
    M_FreeSubstrings( &substrings );
  }
  return name_of_file;
}
