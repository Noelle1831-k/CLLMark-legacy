if (n >= 5) return 0;
int factorial = 1;
for (int i = 2; i <= n; ++i) {
    factorial *= i;
}
return factorial % 10;
}