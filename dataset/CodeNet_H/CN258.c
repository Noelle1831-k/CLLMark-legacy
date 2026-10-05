int main (void){
    int n,c,a[30][4][4],b[30][4][4],i,j,k,l,y,x,max,z;
    while(scanf("%d %d",&n,&c),n!=0 && c!=0){
        for(i=0;i<n;i++){
            for(j=0;j<4;j++){
                for(k=0;k<4;k++){
                    scanf("%d",&a[i][j][k]);
                }
            }
        }
        for(i=0;i<c;i++){
            for(j=0;j<4;j++){
                for(k=0;k<4;k++){
                    scanf("%d",&b[i][j][k]);
                }
            }
        }
        for(i=z=0;i<n;i++){
            max=0;
            for(j=0;j<c;j++){
                y=0;
                for(k=0;k<4;k++){
                    for(l=0;l<4;l++){
                        if(a[i][k][l]==1 && b[j][k][l]==1){
                            y++;
                        }
                    }
                }
                if(max<y){
                    max=y;
                    x=j;
                }
            }
            z+=max;
            for(k=0;k<4;k++){
                for(l=0;l<4;l++){
                    a[i][k][l]-=b[x][k][l];
                    if(a[i+1][k][l]==0 && a[i][k][l]==1) a[i+1][k][l]=1;
                }
            }
        }
        printf("%d\n",z);
    }
    return 0;
}