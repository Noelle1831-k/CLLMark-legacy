int x( int a ) {
  return a * a;
}
int HEXtoINT( char h[ ] ) {
  int i;
  int ans = 0;
  for( i = 0; i < 2; i++ ) {
    ans *= 16;
    if( '0' <= h[ i ] && h[ i ] <= '9' )      ans += h[ i ] - '0';
    else if( h[ i ] == 'A' || h[ i ] == 'a' ) ans += 10;
    else if( h[ i ] == 'B' || h[ i ] == 'b' ) ans += 11;
    else if( h[ i ] == 'C' || h[ i ] == 'c' ) ans += 12;
    else if( h[ i ] == 'D' || h[ i ] == 'd' ) ans += 13;
    else if( h[ i ] == 'E' || h[ i ] == 'e' ) ans += 14;
    else if( h[ i ] == 'F' || h[ i ] == 'f' ) ans += 15;
  }
  return( ans );
}
int main( void ) {
  int col[ 8 ][ 3 ];
  col[ 0 ][ 0 ] = HEXtoINT( "00" ); col[ 0 ][ 1 ] = HEXtoINT( "00" ); col[ 0 ][ 2 ] = HEXtoINT( "00" );
  col[ 1 ][ 0 ] = HEXtoINT( "00" ); col[ 1 ][ 1 ] = HEXtoINT( "00" ); col[ 1 ][ 2 ] = HEXtoINT( "ff" );
  col[ 2 ][ 0 ] = HEXtoINT( "00" ); col[ 2 ][ 1 ] = HEXtoINT( "ff" ); col[ 2 ][ 2 ] = HEXtoINT( "00" );
  col[ 3 ][ 0 ] = HEXtoINT( "00" ); col[ 3 ][ 1 ] = HEXtoINT( "ff" ); col[ 3 ][ 2 ] = HEXtoINT( "ff" );
  col[ 4 ][ 0 ] = HEXtoINT( "ff" ); col[ 4 ][ 1 ] = HEXtoINT( "00" ); col[ 4 ][ 2 ] = HEXtoINT( "00" );
  col[ 5 ][ 0 ] = HEXtoINT( "ff" ); col[ 5 ][ 1 ] = HEXtoINT( "00" ); col[ 5 ][ 2 ] = HEXtoINT( "ff" );
  col[ 6 ][ 0 ] = HEXtoINT( "ff" ); col[ 6 ][ 1 ] = HEXtoINT( "ff" ); col[ 6 ][ 2 ] = HEXtoINT( "00" );
  col[ 7 ][ 0 ] = HEXtoINT( "ff" ); col[ 7 ][ 1 ] = HEXtoINT( "ff" ); col[ 7 ][ 2 ] = HEXtoINT( "ff" );
  while( 1 ) {
    int i, j;
    char ch[ 10 ];
    int cur, min, minI;
    scanf( "%s", ch );
    if( ch[ 0 ] == '0' ) break;
    cur = 0;
    for( i = 0; i < 3; i++ ) cur += x( HEXtoINT( ch + ( i*2+1 ) ) - col[ 0 ][ i ] );
    min = cur;
    minI = 0;
    for( j = 1; j < 8; j++ ) {
      cur = 0;
      for( i = 0; i < 3; i++ )
        cur += x( HEXtoINT( ch + ( i*2+1 ) ) - col[ j ][ i ] );
      if( min > cur ) {
        min = cur;
        minI = j;
      }
    }
    switch( minI ) {
      case 0 : printf( "black\n" );   break;
      case 1 : printf( "blue\n" );    break;
      case 2 : printf( "lime\n" );    break;
      case 3 : printf( "aqua\n" );    break;
      case 4 : printf( "red\n" );     break;
      case 5 : printf( "fuchsia\n" ); break;
      case 6 : printf( "yellow\n" );  break;
      case 7 : printf( "white\n" );   break;
    }
  }
  return( 0 );
}