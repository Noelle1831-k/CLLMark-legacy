int main(void)
{
    int a,b,c;
    int d;
    int x,y;
    while(scanf("%d%d",&a,&b)!=EOF){
    x=a;
    y=b;
    if(a>b)
    {
        for(;;)
        {
            c=a/b;
            d=a%b;
            if(d==0) break;
            b=a;
            b=d;
        }
        d=x/b*y;
        printf("%d %d\n",b,d);
    }
    else
    {
                for(;;)
        {
            c=b/a;
            d=b%a;
            if(d==0) break;
            a=b;
            a=d;
        }
        d=x/a*y;
        printf("%d %d\n",a,d);
    }
    }
    return 0;
}