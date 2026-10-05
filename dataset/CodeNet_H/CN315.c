int check(int a[1000][1000], int n)
{
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i][j] != a[n - 1 - i][j])
                return 0;
            if(a[i][j] != a[i][n - 1 - j])
                return 0;
        }
    }
    return 1;
}
int main(void)
{
    int c, n, i, j, k, r, t, h = 0;
    int a[1000][1000];
    scanf("%d %d", &c, &n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        printf("\n");
    }
    h += check(a, n);
    for(i = 0; i < c - 1; i++) {
        scanf("%d", &k);
        for(j = 0; j < k; j++) {
            scanf("%d %d", &r, &t);
            if(a[r - 1][t - 1] == 1)
                a[r - 1][t - 1]--;
            else
                a[r - 1][t - 1]++;
        }
        h += check(a, n);
    }
    printf("%d\n", h);
    return 0;
}