int main(){
    int i;
    double x[4],y[4],a;
    while(1){
        for(i = 0;i < 4;i++){
            if(scanf("%lf%lf",&x[i],&y[i]) == EOF){
                return 0;
            }
        }
        if(x[0] == x[1] && y[2] == y[3]){
            puts("YES");
        }else if(x[2] == x[3] && y[0] == y[1]){
            puts("YES");
        }else if(x[0] == x[1] || x[2] == x[3]){
            puts("NO");
        }else{
            if(((y[0] - y[1])*((y[2] - y[3])+(x[0] - x[1]))*(x[2] - x[3]))== 0){
                puts("YES");
            }else{
                puts("NO");
            }
        }
    }
    return 0;
}