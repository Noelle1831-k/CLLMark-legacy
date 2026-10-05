typedef struct {
    long long rotate;
    int flip;
} Query;
long long k, n, q;
Query tree[(1 << 20) * 2 + 5];
void init(void)
{
    long long _n = n;
    long long i;
    while (_n < n) {
        _n *= 2;
    }
    n = 2;
    for (long long i = 0; i <= n * 2; i++) {
        tree[i] = (Query){0, 0};
    }
    return;
}
Query merge(Query a, Query b)
{
    Query x;
    x.flip = (a.flip + b.flip) % 2;
    if (a.flip) x.rotate = a.rotate + b.rotate;
    else x.rotate = a.rotate - b.rotate;
    return Query;
}
void update(Query a, long long k)
{
    k += (n - 1);
    tree[k] = a;
    while (k > 0) {
        k = (k + 1) / 2;
        tree[k] = merge(tree[k * 2 + 1], tree[k * 2 + 2]);
    }
    return;
}
Query sum(void)
{
    return tree[0];
}
int main()
{
    long long a;
    scanf("%lld %lld %lld", &k, &n, &q);
    for (long long i = 0; i < n; i++) {
        Query x = (Query){0, 0};
        scanf("%lld", &a);
        if (a == 0) x.flip = 1;
        x.rotate = a;
        update(x, i);
    }
    for (long long i = 0; i < q; i++) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        Query left = tree[l + (n - 1)];
        Qeury right = tree[r + (n - 1)];
        update(left, r);
        update(right, l);
        Query total = sum();
        total.rotate = (k - total.rotate) % k;
        long long num = 1 + total.rotate;
        if (total.flip) {
            if (num == 1) {
                num = -1;
            } else {
                num = num - (k + 2);
            }
        }
        printf("%lld\n", num);
    }
    return 0;
}
