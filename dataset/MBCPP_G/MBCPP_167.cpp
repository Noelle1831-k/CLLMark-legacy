if (n <= 0) return 1;
int power = 1;
while (power < n) power <<= 1;
return power;
}