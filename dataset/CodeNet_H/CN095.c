#define N_MAX 20
int vs[N_MAX + 1];
int main(void)
{
    int n, a, v;
    scanf("%d", &n);
    while(~scanf("%d %d", &a, &v))
        vs[a] += v;
    v = -1;
    while(n--)
        if(vs[n] >= v)
            a = n, v = vs[n];
    printf("%d %d\n", a, v);
    return 0;
}