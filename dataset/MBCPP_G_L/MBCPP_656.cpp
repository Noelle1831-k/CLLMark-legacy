sort(a.begin(), a.end());
sort(b.begin(), b.end());
int minSum = 0;
for (int i = 0; i < n; ++i) {
    minSum += abs(a[i] - b[i]);
}
return minSum;
}