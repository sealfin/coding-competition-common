#include "coding competition common.h"

void p_PleasePressTheReturnKeyTo( const char * const p )
{
  char terminated_by;
  bool end_of_file_encountered;

  printf( "\nPlease press the Return key to %s.", p );
  free( f_ReadStringFromFile( stdin, "\n", &terminated_by, &end_of_file_encountered ));
}
