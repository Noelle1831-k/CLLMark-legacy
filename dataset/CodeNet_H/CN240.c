#define	NUM	1000	
int main( void )
{
	int n;			
	int y;			
	int b;			
	int t;			
	int r;			
	double nowY;	
	double maxY;	
	int maxB;		
	int i;
	while ( 1 ) {
		scanf( "%d", &n );		
		if ( n == 0 ) {
			break;
		}
		maxY = -1;		
		maxB = -1;
		scanf( "%d", &y );		
		for ( i = 0 ; i < n ; i++ ) {
			scanf( "%d %d %d", &b, &r, &t );
			if ( t == 1 ) {
				nowY = ( double )y * ( 1.0 + ( double )y * ( (double)r / 100.0 ) );
			}
			else {
				nowY = ( double )y * pow( 1.0 + ( (double)r / 100.0 ), ( double )y );
			}
			if ( nowY > maxY ) {	
				maxY = nowY;
				maxB = b;
			}
		}
		printf( "%d\n", maxB );
	}
	return 0;
}