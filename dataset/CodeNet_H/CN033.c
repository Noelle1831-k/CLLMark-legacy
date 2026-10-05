int main(void)
{
    int n, i , j, k;
    int d[10];
    int syou;
    scanf( "%d", &n );
    for(i = 0; i < n; i++){
        for(j = 0; j < 10; j++){
        scanf( "%d", &d[j]);
            syou = 0;
                for(k = 0; k < j; k++){
                    if(d[k] > d[j]) syou++;
                }
            if (syou >= 2){
                printf( "NO\n" );
                break;
            }
        }
        if(j == 10) printf( "YES\n" );
    }
    return 0;
}