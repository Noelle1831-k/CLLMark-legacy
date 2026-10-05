#define MAX 100
int cnt[ MAX + 2 ] ;
int main( void )
{
	int N ,max ;
	scanf( "%d" ,&N ) ;
	int i ,p ;
	for( i = max = 0 ; i < N ; ++i )
	{
		scanf( "%d" ,&p ) ;
		++cnt[ p ] ;
		max = max < p ? p : max ;
	}
	for( i = max ; i > 0 ; --i )
	{
		cnt[ i ] += cnt[ i + 1 ] ;
		if( cnt[ i ] >= i )
		{
			printf( "%d\n" ,i ) ;
			return 0 ;
		}
	}
}
