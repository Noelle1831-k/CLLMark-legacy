int main(void){
    int a,b,c,d,x;
    int e,f,g,h,y;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    scanf("%d %d %d %d",&e,&f,&g,&h);
    x=a+b+c+d;
    y=e+f+g+h;
    if(x<y){
        printf("%d\n",y);
    }
    else if(y<x){
        printf("%d\n",x);
    }
    else if(x==y){
        printf("%d(=%d)",x,y);
    }
    return 0;
}