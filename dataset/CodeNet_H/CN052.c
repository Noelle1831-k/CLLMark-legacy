int akkari___n( int n, int m ){
  int counter = 0;
  while( !( n % m ) ){
      counter++;
      n /= m;
    }
  return counter;
}
int min( int x, int y ){
  return ( x < y ) ? x : y;
}
int main( void ){
  int n, i, c2, c5;
  while( 1 ){
    scanf( "%d", &n );
    if( !n ){ return 0; }
    c2 = 0;
    c5 = 0;
    for( i = n; i >= 2; i-- ){
      c2 += akkari___n( i, 2 );
      c5 += akkari___n( i, 5 );
    }
    printf( "%d\n", min( c2, c5 ) );
  }
}