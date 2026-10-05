long speller( char *fake ,char *now )
{
	int ret = 0 ;
	int fake_p = 0 ,now_p = 0 ;
	if( now[ now_p ] == '\0' )
	{
		return 1 ;
	}
	while( fake[ fake_p ] != '\0' )
	{
		if( fake[ fake_p ] == now[ now_p ] )
		{
			ret += speller( fake + fake_p + 1 ,now + 1 ) ;
			now_p ;
			if( now[ now_p ] == '\0' )
			{
				return ret ;
			}
		}
		++fake_p ;
	}
	return ret ;	
}
int main()
{
	char fake_spell[ 1000 + 1 ] ;
	scanf( "%s" ,fake_spell ) ;
	char spell[ 1000 + 1 ] ;
	scanf( "%s" ,spell ) ;
	printf( "%ld\n" ,speller( fake_spell ,spell ) ) ;
	return 0 ;
}