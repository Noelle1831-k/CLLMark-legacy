if (n == 0) return 2;
if (n == 1) return 1;
int a = 2, b = 1, c;
for (int i = 2; i <= n; i++) {
    c = b + 2 * a;
    a = b;
    b = c;
}
return c;
}