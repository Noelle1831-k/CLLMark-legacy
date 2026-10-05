int main(void)
{
    int k, p;
    int n;
    int i;
    int ans;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d %d", &k, &p);
        ans = k % p;
        if (ans == 0){
            ans = p;
        }
        printf("%d\n", ans);
    }
    return (0);
}