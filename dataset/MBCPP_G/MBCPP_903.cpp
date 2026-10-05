int totalBits = n * (int)log2(n+1);
int setBits = 0;
for (int i = 1; i <= n; ++i) {
    setBits += __builtin_popcount(i);
}
return totalBits - setBits;
}