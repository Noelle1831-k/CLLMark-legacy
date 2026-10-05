int count = 0;
for (int i = 1; i <= n; ++i) {
    if (__builtin_popcount(i) % 2 == 1) {
        ++count;
    }
}
return count;
}