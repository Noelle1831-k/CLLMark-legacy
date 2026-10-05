int main(){
    int n,m,s[99999],a[100000],ans=0,p=0,i,j;
    scanf("%d%d",&n,&m);
    for (i=0; i<n-1; i++) {
        scanf("%d",&s[i]);
    }
    for (i=0; i<m; i++) {
        scanf("%d",&a[i]);
        if (a[i]>0) {
            for (j=0; j<a[i]; j++) {
                ans+=s[p];
                p++;
            }
        }else{
            for (j=0; j>a[i]; j--) {
                ans+=s[p-1];
                p--;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}