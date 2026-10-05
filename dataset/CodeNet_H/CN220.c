int main (
  int     argc,
  char  * argv[ ]
  )
{
  int i;
  for ( ; ; )
  {
    char s[ 16 ] = { '1' };
    int a, b;
    scanf ( " %d.%s", &a, s + 1 );
    if ( a < 0 )  break ;
    for ( b = atoi ( s ); b < 10000; b *= 10 );
    b -= 10000;
    if ( a >= 0x100 || !!( b % 625 ) )
    {
      puts ( "NA" );
      continue ;
    }
    for ( i = 0x100; i; i >>= 1 )
    {
      putchar ( '0' + !!( a & i ) );
    }
    putchar ( '.' );
    for ( i = 10000; i != 625; i /= 2 )
    {
      putchar ( '0' + !!( ( b % i ) * 2 / i ) );
    }
  }
  return ( 0 );
}