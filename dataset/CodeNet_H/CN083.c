int main()
{
        int year, month, day, conv, nen;
        char str[9];
        while ( scanf( "%d %d %d", &year, &month, &day ) != EOF ) {
                sprintf( str, "%d%02d%02d", year, month, day );
                conv = atoi( str );
                if ( conv < atoi( "18680908" ) ) {
                        printf( "pre-meiji\n" );
                } else if ( conv >= atoi( "18680908" ) && conv <= atoi( "19120729" ) ) {
                        nen = year - 1868 + 1;
                        printf( "meiji %d %d %d\n", nen, month, day );
                } else if ( conv >= atoi( "19120730" ) && conv <= atoi( "19261224" ) ) {
                        nen = year - 1912 + 1;
                        printf( "taisho %d %d %d\n", nen, month, day );
                } else if ( conv >= atoi( "19261225" ) && conv <= atoi( "19890107" ) ) {
                        nen = year - 1926 + 1;
                        printf( "showa %d %d %d\n", nen, month, day );
                } else if ( conv >= atoi( "19890108" ) ) {
                        nen = year - 1989 + 1;
                        printf( "heisei %d %d %d\n", nen, month, day );
                }
        }
        return 0;
}
