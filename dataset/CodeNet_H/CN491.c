int main (void){
    int N_num;
    int K_num;
    int dp[258][3][2]={{{0}}};
    int i,j,k,l;
    int date,kind;
    int ans=0;
    scanf("%d%d",&N_num,&K_num);
    for(i=0;i<N_num;i++){
        for(j=0;j<3;j++){
            for(k=0;k<2;k++){
                dp[i][j][k]=0;
            }
        }
    }
    for(i=0;i<3;i++)dp[0][i][0]=1;
    for(i=0;i<K_num;i++){
        scanf("%d%d",&date,&kind);
        for(j=0;j<3;j++){
            if(j!=kind-1){
                for(k=0;k<2;k++){
                    dp[date-1][j][k]=-1;
                }
            }
        }
    }
    for(i=0;i<N_num;i++){
        for(j=0;j<3;j++){
            if(dp[i][j][0]!=-1){
                for(k=0;k<2;k++){
                    switch(k){
                    case 0:
                        for(l=0;l<3;l++){
                            if(j==l){
                                if(dp[i+1][l][1]!=-1){
                                    dp[i+1][l][1]+=dp[i][j][0];
                                    dp[i+1][l][1]%=10000;
                                }
                            }else{
                                if(dp[i+1][l][0]!=-1){
                                    dp[i+1][l][0]+=dp[i][j][0];
                                    dp[i+1][l][0]%=10000;
                                }
                            }
                        }
                        break;
                    case 1:
                        for(l=0;l<3;l++){
                            if(j==l){
                            }else{
                                if(dp[i+1][l][0]!=-1){
                                    dp[i+1][l][0]+=dp[i][j][1];
                                    dp[i+1][l][0]%=10000;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            if(dp[N_num-1][i][j]!=-1){
                ans+=dp[N_num-1][i][j];
                ans%=10000;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}