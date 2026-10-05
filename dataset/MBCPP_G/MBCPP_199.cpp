if (n < 1) return 0;
int res = 1;
while (res <= n) res <<= 1;
return res >> 1;
}