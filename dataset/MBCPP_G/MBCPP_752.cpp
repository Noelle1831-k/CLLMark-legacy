if (n == 0) return 0;
if (n == 1) return 1;
int prev2 = 0, prev1 = 1, current;
for (int i = 2; i <= n; ++i) {
    current = prev1 + 2 * prev2;
    prev2 = prev1;
    prev1 = current;
}
return current;
}