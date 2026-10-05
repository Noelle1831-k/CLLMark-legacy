#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b
int main(){
    int n,i,x,y,k;
    scanf("%d%d",&n,&k);
    for(;k-->0;){
        scanf("%d%d",&x,&y);
        x--;y--;
        x=min(x,n-1-x);
        y=min(y,n-1-y);
        x=min(x,y);
        printf("%d\n",x%3+1);
    }
    return 0;
}