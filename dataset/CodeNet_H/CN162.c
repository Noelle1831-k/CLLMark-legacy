int main(void){
    unsigned long long int m,n,i,s,t = 108839116800000000;
    while(scanf("%llu",&m) , m != 0){
        scanf("%llu",&n);
        s = 0;
        for(i = m;i <= n;i++){
            if(!(t % i)){
                s++;
            }
        }
        printf("%llu\n",s);
    }
    return 0;
}