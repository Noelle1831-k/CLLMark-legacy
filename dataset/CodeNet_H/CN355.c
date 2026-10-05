int main(void){
    int i,a,b,n,s,e;
    scanf("%d %d\n%d",&a,&b,&n);
    for(i=0;i<n;++i){
        scanf("%d %d",&s,&e);
        if(b>s&&a<e){
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
}
