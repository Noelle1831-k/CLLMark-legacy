int main(void) {
    int q,c,a,n,i,j,count;
    scanf("%d",&q);
    for (i=0; i<q; i++) {
        count=0;
        scanf("%d%d%d",&c,&a,&n);
        if (c<=a&&c<=n) {
            count+=c;
            a-=c,n-=c,c=0;
        } else if (a<=c&&a<=n) {
            count+=a;
            c-=a,n-=a,a=0;
        } else {
            count+=n;
            c-=n,a-=n,n=0;
        }
        if (a<=2*c) {
            count+=a;
            c-=2*a,a=0;
        } else {
            count+=c/2;
            a-=c/2,c-=0;
        }
        count+=c/3;
        printf("%d\n",count);
    }
    return 0;
}