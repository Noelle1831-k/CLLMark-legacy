void main()
{
    int n;
    printf("Enter the value of n\n\n");
    scanf("%d",&n);
    if(n<=20)
    {
    float sum,i;
    sum=1;
    i=1;
    while(i<=n)
    {
        sum=sum*i;
        i++;
    }
    printf("1*2*........*%d=%.0f\n\n",n,sum);
    }
    else
        printf("Enter the range value");
}