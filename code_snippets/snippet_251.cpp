    int binomial[n+1];
    binomial[0]=1;
    binomial[1]=1;
    binomial[2]=2;
    for(int i=3;i<=n;i++){
        binomial[i]=(binomial[i-1]+binomial[i-2])%1000000007;
    }
    int sum=0;
    for(int i=0;i<n;i=i+2){
        sum=(sum+binomial[i])%1000000007;
    }
    return sum;
}
<|endoftext|>