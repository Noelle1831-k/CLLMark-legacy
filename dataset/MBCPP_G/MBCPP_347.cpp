int count = 0;
for (int i = 1; i <= min(m, n); ++i) {
    count += (m - i + 1) * (n - i + 1);
}
return count;
}