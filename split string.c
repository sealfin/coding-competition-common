#include "coding competition common.h"

static char *f_AddCharacterToSubstring( char *p_substring, size_t * const p_lengthOfSubstring, const char p_character )
{
  if( p_substring == NULL )
  {
    p_substring = ( char* )M_malloc_WithErrorChecking( sizeof( char ), "p_substring" );
    *p_lengthOfSubstring = 1;
  }
  else
  {
    p_substring = ( char* )M_realloc_WithErrorChecking( p_substring, sizeof( char ) * ( *p_lengthOfSubstring + 1 ), "p_substring" );
    ( *p_lengthOfSubstring ) ++;
  }
  p_substring[ *p_lengthOfSubstring - 1 ] = p_character;
  return p_substring;
}

static void p_AddSubstring( t_Substrings * const p_substrings, char *p_substring )
{
  if( p_substrings->m_numberOfSubstrings == 0 )
    p_substrings->m_substrings = ( char** )M_malloc_WithErrorChecking( sizeof( char* ), "p_substrings->m_substrings" );
  else
    p_substrings->m_substrings = ( char** )M_realloc_WithErrorChecking( p_substrings->m_substrings, sizeof( char* ) * ( p_substrings->m_numberOfSubstrings + 1 ), "p_substrings->m_substrings" );
  p_substrings->m_substrings[ p_substrings->m_numberOfSubstrings ++ ] = p_substring;
}

t_Substrings f_SplitString( const char * const p_string, const char * const p_nameOfString, t_SplitStringDecision ( *p_function )( char, void* ), const char * const p_nameOfFunction, void *p_functionData, const char * const p_nameOfFile, const unsigned int p_lineInFile )
{
  t_Substrings substrings;

  substrings.m_numberOfSubstrings = 0;
  substrings.m_substrings = NULL;

  if(( p_string == NULL ) || ( p_function == NULL ))
  {
    fprintf( stderr, "Sorry, an error occurred: `%s` is `NULL` on line %u of the file \"%s\".\n", ( p_string == NULL )?p_nameOfString:p_nameOfFunction, p_lineInFile, p_nameOfFile );
    if(( p_string != NULL ) && ( p_function == NULL ))
    {
      substrings.m_substrings = ( char** )M_malloc_WithErrorChecking( sizeof( char* ), "substrings.m_substrings" );
      substrings.m_substrings[ 0 ] = ( char* )M_malloc_WithErrorChecking( sizeof( char ) * ( strlen( p_string ) + 1 ), "substrings.m_substrings[ 0 ]" );
      strcpy( substrings.m_substrings[ 0 ], p_string );
      substrings.m_numberOfSubstrings = 1;
    }
  }
  else
  {
    size_t i = 0;
    const size_t length_of_string = strlen( p_string );
    char *substring = NULL;
    size_t length_of_substring;

    for( ; i < length_of_string; i ++ )
    {
      const char c = p_string[ i ];

      switch( p_function( c, p_functionData ))
      {
        case k_SplitStringDecision_RetainCharacter:
          substring = f_AddCharacterToSubstring( substring, &length_of_substring, c );
          break;
        case k_SplitStringDecision_DiscardCharacter:
          break;
        case k_SplitStringDecision_EndSubstring:
          if( substring != NULL )
          {
            substring = f_AddCharacterToSubstring( substring, &length_of_substring, '\0' );
            p_AddSubstring( &substrings, substring );
            substring = NULL;
          }
          break;
      }
    }
    if( substring != NULL )
    {
      substring = f_AddCharacterToSubstring( substring, &length_of_substring, '\0' );
      p_AddSubstring( &substrings, substring );
    }
  }

  return substrings;
}
