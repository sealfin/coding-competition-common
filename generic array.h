#ifndef generic_array_h

#define generic_array_h

#include "coding competition common.h"

template <class T>
class GenericArray
{
  private:
    size_t m_length;
    T m_default, *m_array;

  public:
    GenericArray( T p )
    {
      m_length = 0;
      m_default = p;
    }

    ~GenericArray( void )
    {
      p_Empty();
    }

  protected:
    /* If your class overrides the following method, your class must have a destructor, and that destructor must invoke the `p_Empty()` method of this class. */
    virtual void p_Delete( T p )
    {
    }

  public:
    void p_Empty( void )
    {
      if( m_length > 0 )
      {
        size_t i = 0;

        for( ; i < m_length; i ++ )
          p_Delete( m_array[ i ] );
        free( m_array );
        m_length = 0;
      }
    }

    size_t f_Length( void )
    {
      return m_length;
    }

    T& operator[]( const size_t p )
    {
      if( p >= m_length )
      {
        if( m_length == 0 )
          m_array = ( T* )M_malloc_WithErrorChecking( sizeof( T ) * ( p + 1 ), "m_array" );
        else
          m_array = ( T* )M_realloc_WithErrorChecking( m_array, sizeof( T ) * ( p + 1 ), "m_array" );

        size_t i = m_length;

        for( ; i <= p; i ++ )
          m_array[ i ] = m_default;
        m_length = p + 1;
      }
      return m_array[ p ];
    }

    void p_Append( T p )
    {
      operator[]( m_length ) = p;
    }
};

#endif
