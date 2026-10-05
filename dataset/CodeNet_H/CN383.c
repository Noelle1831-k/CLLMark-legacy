#define gc getchar
int scan(int*N)
{
	int c,n=0;
	for(c=gc();'0'<=c&&c<='9';c=gc())
	    n=(n*10)+(c&0xf);
	if(N!=NULL)*N=n;
	return n;
}
#define N_MAX 3000
typedef struct
{
    int x;
    int y;
}Point;
int N;          
int K;          
Point P[N_MAX]; 
Point C[N_MAX]; 
int comp(const void *a, const void *b)
{
    return ((Point *)b)->x * ((Point *)a)->y - ((Point *)a)->x * ((Point *)b)->y;
}
int cnt(int n)
{
    Point c;
    c = C[0];
    int L=2;    
    int M=2;    
    qsort(C, n, sizeof(Point), comp);
    for(int i=1; i<n; i++){
        L += (c.x * C[i].y) == (C[i].x * c.y);
        if(L > M) M=L;
        else{ L=2, c=C[i]; }
    }
    return M;
}
int main()
{
    int i,j;
    int n;
    int v;
    int ans=0;
    scan(&N);
	scan(&K);
    for(i=0; i<N; i++){
        scan(&P[i].x);
    	scan(&P[i].y);
    }
    for (i=0; i<=(N-K); i++){
        v=1,n=0;
        for (j=i+1; j<N; j++){
            if ( P[i].x == P[j].x ){
                v++;
            }else{
                C[n] = P[j];
                C[n].x -= P[i].x;
                C[n].y -= P[i].y;
            	n++;
            }
        }
        if ( v>=K || cnt(n)>=K ){
            ans=1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
