#define MAX_WH 21
int main( void )
{
	char top_down[ MAX_WH +1 ] ;
	char center[ MAX_WH +1 ] ;
	char other[ MAX_WH +1 ] ;
	int W ,H ;
	char initial ;
	scanf( "%d %d%*c%c" ,&W ,&H ,&initial ) ;
	int centerW = W / 2 ;
	int centerH = H / 2 ;
	memset( top_down ,'-' ,W ) ;
	memset( other ,'.' ,W ) ;
	top_down[ W - 1 ] = top_down[ 0 ] = '+' ;
	other[ W - 1 ] = other[ 0 ] = '|' ;
	other[ W ] = top_down[ W ] = '\0' ;
	sprintf( center ,"%s" ,other ) ;
	center[ centerW ] = initial ;
	int i ;
	for( i = 0 ; i < H ; ++i )
	{
		char *output ;
		if( i == 0 || i == H - 1 )
		{
			output = top_down ;
		}
		else if( i == centerH )
		{
			output = center ;
		}
		else
		{
			output = other ;
		}
		printf( "%s\n" ,output ) ;
	}
	return 0 ;
}
