#ifndef coding_competition_common_h

#define coding_competition_common_h

#include "seal_bool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long
#ifndef LEONARDO
long
#endif
t_UnsignedLong;

#ifdef LEONARDO
#define k_UnsignedLong_printf_Format "%lu"
#define t_UnsignedLong_printf_Typecast t_UnsignedLong
#endif

#ifdef __MWERKS__
#define k_UnsignedLong_printf_Format "%lu"
#define t_UnsignedLong_printf_Typecast unsigned long
#endif

#if !( defined( LEONARDO ) || defined( __MWERKS__ ))
#define k_UnsignedLong_printf_Format "%llu"
#define t_UnsignedLong_printf_Typecast t_UnsignedLong
#endif

#ifdef __cplusplus
extern "C"
{
#endif

void p_WriteUnsignedLongToFile( FILE * const p_file, const t_UnsignedLong p_unsignedLong );

/* If your code invokes the `?_malloc_WithErrorChecking()` or/and `?_realloc_WithErrorChecking()` function(s) or/and macro(s), or/and the `f_ReadStringFromFile()` function, the following procedure must be implemented. */
void p_Exit( const int p );

void *f_malloc_WithErrorChecking( const size_t p_sizeInBytes, const char * const p_nameOfPointer, const char * const p_nameOfFile, const unsigned int p_lineInFile );

#define M_malloc_WithErrorChecking( p_sizeInBytes, p_nameOfPointer )               \
  f_malloc_WithErrorChecking( p_sizeInBytes, p_nameOfPointer, __FILE__, __LINE__ )

void *f_realloc_WithErrorChecking( void *p_originalMemory, const size_t p_sizeInBytes, const char * const p_nameOfPointer, const char * const p_nameOfFile, const unsigned int p_lineInFile );

#define M_realloc_WithErrorChecking( p_originalMemory, p_sizeInBytes, p_nameOfPointer )               \
  f_realloc_WithErrorChecking( p_originalMemory, p_sizeInBytes, p_nameOfPointer, __FILE__, __LINE__ )

char *f_ReadStringFromFile( FILE * const p_file, const char * const p_mayBeTerminatedBy, char * const p_terminatedBy, bool * const p_endOfFileEncountered );

#ifdef __cplusplus
}
#endif

typedef enum
{
  k_StringToUnsignedIntError_None,
  k_StringToUnsignedIntError_p_string_Is_NULL,
  k_StringToUnsignedIntError_p_string_IsZeroCharactersInLength,
  k_StringToUnsignedIntError_multiplier_IsGreaterThan_UINT_MAX,
  k_StringToUnsignedIntError_value_IsGreaterThan_UINT_MAX,
  k_StringToUnsignedIntError_p_string_ContainsANonDigitCharacter
}
t_StringToUnsignedIntError;

#ifdef __cplusplus
extern "C"
{
#endif

t_StringToUnsignedIntError f_StringToUnsignedInt( const char * const p_string, unsigned int * const p_unsignedInt );

bool f_AdditionWillOverflow( const t_UnsignedLong p_a, const t_UnsignedLong p_b, const size_t p_numberOfBits );

#define M_AdditionWillOverflow( p_a, p_b )                         \
  f_AdditionWillOverflow( p_a, p_b, sizeof( t_UnsignedLong ) * 8 )

#ifdef __cplusplus
}
#endif

typedef enum
{
  k_StringToUnsignedLongError_None,
  k_StringToUnsignedLongError_p_string_Is_NULL,
  k_StringToUnsignedLongError_p_string_IsZeroCharactersInLength,
  k_StringToUnsignedLongError_multiplier_Overflowed,
  k_StringToUnsignedLongError_value_to_assign_Overflowed,
  k_StringToUnsignedLongError_value_Overflowed,
  k_StringToUnsignedLongError_p_string_ContainsANonDigitCharacter
}
t_StringToUnsignedLongError;

#ifdef __cplusplus
extern "C"
{
#endif

t_StringToUnsignedLongError f_StringToUnsignedLong( const char * const p_string, t_UnsignedLong * const p_unsignedLong );

#ifdef __cplusplus
}
#endif

#endif