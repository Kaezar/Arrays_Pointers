#include <stdio.h>
#include <stdlib.h>

// Create a name for a pointer to a
// function that has two double precision
// floating point arguments and returns to
// its caller a double precision floating
// point value.
typedef double (*myFunctionPointer)(double a,double b) ;

// Here's a declaration of a pointer to
// a function that has two double arguments
// and returns a double to its caller.
double (*functionPointer)(double a, double b) ;

// Declare and define four simple functions.
double add( double x, double y ) {
  return x + y ;
} // add( double, double )

double subtract( double x, double y ) {
  return x - y ;
} // subtract( double, double )

double multiply( double x, double y ) {
  return x * y ;
} // multiply( double, double )

double divide( double x, double y ) {
  return x / y ;
} // divide( double, double )

// Define a data structure
// that contains pointers to functions.
struct calculator {
  myFunctionPointer ap ;
  myFunctionPointer sp ;
  myFunctionPointer mp ;
  myFunctionPointer dp ;
} ;


// Create aliases for the struct and for pointers
// to the struct.
typedef struct calculator Calculator, *CalculatorPointer ;

CalculatorPointer makeCalculator() {
  CalculatorPointer cp = (CalculatorPointer) malloc(sizeof(Calculator));

  cp->ap = add ;
  cp->sp = subtract ;
  cp->mp = multiply ;
  cp->dp = divide ;
  return cp;
}

int main( int argc, char **argv ) {

  functionPointer = add ;

  printf( "size of function pointer = %lu\n",
      sizeof(functionPointer)) ;
  printf( "3 + 4 = %8.4f\n", functionPointer(3,4)) ;

  CalculatorPointer cp = makeCalculator();


  printf( "\n\n" ) ;

  // Compute and print sum, difference, product,
  // and quotient. Show how to use a pointer
  // to a struct and pointers to functions.
  printf( "3 + 4 = %8.4f\n", cp->ap(3,4) ) ;
  printf( "3 - 4 = %8.4f\n", cp->sp(3,4) ) ;
  printf( "3 * 4 = %8.4f\n", cp->mp(3,4) ) ;
  printf( "3 / 4 = %8.4f\n", cp->dp(3,4) ) ;

  // Compute and print same results once
  // again, but this time showing another
  // way to use the pointers.
  printf( "\n\n" ) ;

  printf( "3 + 4 = %8.4f\n", (*cp).ap(3,4) ) ;
  printf( "3 - 4 = %8.4f\n", (*cp).sp(3,4) ) ;
  printf( "3 * 4 = %8.4f\n", (*cp).mp(3,4) ) ;
  printf( "3 / 4 = %8.4f\n", (*cp).dp(3,4) ) ;


} // main( int, char **  )
