if (b == 0) return 1;
if (b < 0) return 1 / power(a, -b);
int half = power(a, b / 2);
if (b % 2 == 0) return half * half;
else return a * half * half;
}