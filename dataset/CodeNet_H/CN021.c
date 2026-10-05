int main(void){
    int n,i;
    double x1,x2,x3,x4,y1,y2,y3,y4,katamuki1,katamuki2;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf\n",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        katamuki1=(y2-y1)/(x2-x1);
        katamuki2=(y4-y3)/(x4-x3);
        if(katamuki2==katamuki1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
