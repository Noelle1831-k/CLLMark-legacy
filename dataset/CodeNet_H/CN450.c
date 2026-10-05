int main(void) {
    int n, i, c;
    int stk[100001], si, last_color, total;
    while (scanf("%d", &n) == 1 && n) {
        memset(stk + 1, 0, n * sizeof(int));
        scanf("%d", &c);
        si = 1;
        stk[si] = 1;
        last_color = c;
        for (i = 2; i <= n; i++) {
            scanf("%d", &c);
            if (i&1) {
                stk[si += last_color != c]++;
            }
            else {
                if (last_color != c && si > 1) {
                    stk[si-1] += stk[si];
                    stk[si] = 0;
                    si--;
                }
                stk[si]++;
            }
            last_color = c;
        }
        for (i = si - (last_color != 0), total = 0;
             i > 0; i -= 2) {
            total += stk[i];
        }
        printf("%d\n", total);
    }
    return 0;
}