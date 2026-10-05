int main(void){
    int train[10000],i=0,j,latte[10000],x,k;
    while(scanf("%d",&x)!=EOF){
        train[i]=x;
        i++;
    }
    for(j=0;j<=i;j++){
        if(train[j]==0){
            for(k=j-1;k>=0;k--){
                if(train[k]!=0){
                    printf("%d\n",train[k]);
                    train[k]=0;
                    break;
                }
            }
        }
    }
    return 0;
}