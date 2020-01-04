#include "coding competition common.h"

char *f_ReadStringFromFile( FILE * const p_file, const char * const p_mayBeTerminatedBy, char * const p_terminatedBy, bool * const p_endOfFileEncountered )
{
   char c, *string = ( char* )M_malloc_WithErrorChecking( sizeof( char ), "string" );
   size_t string_length = 1, i;

   l_Loop:
   if( fscanf( p_file, "%c", &c ) == EOF )
   {
      *p_endOfFileEncountered = true;
      string[ string_length - 1 ] = '\0';
      return string;
   }
   for( i = 0; i < strlen( p_mayBeTerminatedBy ); i ++ )
      if( c == p_mayBeTerminatedBy[ i ] )
      {
         *p_terminatedBy = c;
         *p_endOfFileEncountered = false;
         string[ string_length - 1 ] = '\0';
         return string;
      }
   string[ string_length - 1 ] = c;
   string = ( char* )M_realloc_WithErrorChecking( string, sizeof( char ) * ( string_length + 1 ), "string" );
   string_length ++;
   goto l_Loop;
}