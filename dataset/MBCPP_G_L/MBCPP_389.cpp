if (n == 0) return 2;
if (n == 1) return 1;
int a = 2, b = 1, c;
for (int i = 2; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
}
return b;
}