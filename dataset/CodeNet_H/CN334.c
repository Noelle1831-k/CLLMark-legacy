void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(void)
{
    int n, i, j, h = 0;
    int a[128];
    scanf("%d", &n);
    n *= 3;
    for(i = 0; i < n; i += 3)
        scanf("%d %d %d", &a[i], &a[i + 1], &a[i + 2]);
    for(i = 0; i < n; i += 3) {
        if(a[i] > a[i + 1]) swap(&a[i], &a[i + 1]);
        if(a[i] > a[i + 2]) swap(&a[i], &a[i + 2]);
        if(a[i + 1] > a[i + 2]) swap(&a[i + 1], &a[i + 2]);
    }
    for(i = 0; i < n; i += 3) {
        for(j = 0; i < n; i += 3) {
            if(a[i] == a[j] && a[i + 1] == a[j + 1] && a[i + 2] == a[j + 2]) {
                h++;
                a[j] = 0;
                a[j + 1] = 0;
                a[j + 2] = 0;
            }
        }
    }
    for(i = 0; i < n; i += 3)
        printf("%d %d %d\n", a[i], a[i + 1], a[i + 2]);
    printf("%d\n", h);
    return 0;
}
