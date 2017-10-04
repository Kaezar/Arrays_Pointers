#include <stdio.h>
#include <stdlib.h>

struct node {
  int value ;
  struct node* lp;
  struct node* rp;
} ;

typedef struct node Node ;
typedef struct node* NodePointer;

NodePointer createRoot( int n ) {
  NodePointer np = (NodePointer) malloc( sizeof(Node) ) ;
  np->value = n ;
  np->lp = NULL ;
  np->rp = NULL ;
  return np ;
} // createRoot( int )

NodePointer addNode( NodePointer np, int n ) {
  NodePointer rp = np ;

  if( np == NULL ) {
    rp = createRoot( n ) ;
  } // if
  else if( n < np->value ) {
    if( np->lp == NULL ) {
      np->lp = createRoot( n ) ;
    } // if
    else {
      np->lp = addNode( np->lp, n ) ;
    } // else
  } // else if
  else if( n > np->value ) {
    if( np->rp == NULL ) {
      np->rp = createRoot( n ) ;
    } // if
    else {
      np->rp = addNode( np->rp, n ) ;
    } // else
  } // else if
  else {
    // if value to be added is already in tree, do nothing
    // (do not add duplicate values to tree)
  } // /else

  return rp;
} // addNode( NodePointer, int )

void printNodes( NodePointer np ) {
  if( np != NULL ) {
    printNodes( np->lp ) ;
    printf( "value at node = %4d\n", np->value ) ;
    printNodes( np->rp ) ;
  } // if
} // printNodes( NodePointer )

int height(NodePointer np) {
  if (np == NULL) {
    return 0;
  }
  else {
    int leftHeight = height(np->lp);
    int rightHeight = height(np->rp);

    if(leftHeight > rightHeight) 
      return (leftHeight+1);
      else return (rightHeight+1);
  }
}

int main( int argc, char** argv ) {

  if( argc > 1 ) {

    NodePointer rp = createRoot( atoi(argv[1]) ) ;

    int i;
    for( i = 2; i < argc; i++ ) {
      rp = addNode( rp, atoi(argv[i]) ) ;
    } // for

    printNodes( rp ) ;
    printf("Height of tree = %d\n", height(rp));
  } // if

} // main( int, char** )