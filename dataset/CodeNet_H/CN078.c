int b[15][15];
void reset(){
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            b[i][j]=0;
        }
    }
}
void magic_square(int x,int y,int n,int c){
    if(c==n*n)return;
    if(b[x][y]==0){
        b[x][y]=++c;
        if(++x==n)x=0;
        if(++y==n)y=0;
        magic_square(x,y,n,c);
    }else{
        if(++x==n)x=0;
        if(--y==-1)y=n-1;
        magic_square(x,y,n,c);
    }
}
int main(){
    int n,i,j;
    while(scanf("%d",&n),n){
        reset();
        magic_square(n/2+1,n/2,n,0);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j<n-1)printf("%4d ",b[i][j]);
                else printf("%4d\n",b[i][j]);
            }
        }
    }
    return 0;
}