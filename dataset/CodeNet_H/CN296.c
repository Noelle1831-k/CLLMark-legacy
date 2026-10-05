int prev[ 200000 + 1 ] ,next[ 200000 + 1 ] ;
int main()
{
    int n ,m ,q ;
    int a , r ,p = 0 ;
    int i ,j ;
    scanf( "%d %d %d", &n , &m , &q ) ;
    for( i = 0 ; i < n ; i++ )
    {
        prev[ i ] = ( i - 1 + n ) % n ;
        next[ i ] = ( i + 1 ) % n ;
    }
    for( i = 0 ; i < m ; i++ )
    {
        scanf( "%d", &a ) ;
        for( j = 0 ; j < a ; j++ )
        {
            p = a % 2 == 0 ? next[ p ] : prev[ p ] ;
        }
        r = p ;
        next[ prev[ p ] ] = next[ p ] ;
        prev[ next[ p ] ] = prev[ p ] ;
        p = next[ p ] ;
        next[ r ] = -1 ;
        prev[ r ] = -1 ;
    }
    for( i = 0 ; i < q ; i++ )
    {
        scanf( "%d", &a ) ;
        if( prev[ a ] == -1 )
        {
            printf( "0\n" ) ;
        }
        else
        {
            printf( "1\n" ) ;
        }
    }
    return 0 ;
}