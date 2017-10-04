#include <stdio.h>
#include <stdlib.h>
// this function does nothing
void f( int n ) {
  n = 42;
} // f( int )
// this function does something
void g( int *np ) {
  *np = 42;
} // g( int* )

int main( int argc, char** argv ) {
  // create an array in a familiar way
  int primes[8];
  primes[0] = 2;
  primes[1] = 3;
  primes[2] = 5;
  primes[3] = 7;
  primes[4] = 11;
  primes[5] = 13;
  primes[6] = 17;
  primes[7] = 19;

  // access elements with both index and pointer plus offset
  printf( "primes[0]     = %2d\n", primes[0] );
  printf( "*primes       = %2d\n", *primes );

  printf( "\n" );

  printf( "primes[1]     = %2d\n", primes[1] );
  printf( "*(primes + 1) = %2d\n", *(primes + 1) );

  printf( "\n" );

  printf( "primes[2]     = %2d\n", primes[2] );
  printf( "*(primes + 2) = %2d\n", *(primes + 2) );

  printf( "\n" );

  printf( "primes[3]     = %2d\n", primes[3] );
  printf( "*(primes + 3) = %2d\n", *(primes + 3) );

  printf( "\n" );

  *(primes + 7) = 21;
  printf( "primes[7] = %d\n", primes[7] );

  printf( "\n" );

  // another way to create an array
  int* fibonacci = (int*) malloc( 8 * sizeof(int) );
  // assign values using name of array plus index
  fibonacci[0] = 1;
  fibonacci[1] = 1;
  fibonacci[2] = 2;
  fibonacci[3] = 3;
  // assign values using address of start of
  // block of memory plus offset
  *(fibonacci + 4) = 5;
  *(fibonacci + 5) = 8;
  *(fibonacci + 6) = 13;
  *(fibonacci + 7) = 21;

  int i;
  for( i = 0; i < 8; i++ ) {
    printf( "fibonacci[%1d] = %2d\n", i, fibonacci[i] );
  } // for

  printf( "\n" );

  for( i = 0; i < 8; i++ ) {
    printf( "address of fibonacci[%1d] = %lu\n",
        i, (unsigned long) (fibonacci + i) );
  } // for

  printf( "\n" );

  int oneInteger = 27;
  printf( "before call to f(), oneInteger = %d\n", oneInteger );
  f( oneInteger );
  printf( "after call to f(), oneInteger  = %d\n", oneInteger );

  printf( "\n" );

  int oneIntegerArray[1];
  oneIntegerArray[0] = 27;
  printf( "before call to g(), oneIntegerArray[0] = %d\n",
      oneIntegerArray[0] );
  printf( "before call to g(), ");
  printf( "address of oneIntegerArray[0] = %lu\n",
      (unsigned long) &oneIntegerArray[0] );
  g( oneIntegerArray );
  printf( "after call to g(), oneIntegerArray[0]  = %d\n",
      oneIntegerArray[0] );
  printf( "after call to g(), " );
  printf( "address of oneIntegerArray[0]  = %lu\n",
      (unsigned long) &oneIntegerArray[0] );
  
} // main( int, char** )