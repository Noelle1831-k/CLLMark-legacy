if (n == 0) return 0;
int sumParts = breaksum(n / 2) + breaksum(n / 3) + breaksum(n / 4);
return max(n, sumParts);
}