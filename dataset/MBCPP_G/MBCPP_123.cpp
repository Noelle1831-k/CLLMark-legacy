vector<int> divisorSums(limit + 1, 0);
for (int i = 1; i <= limit; ++i) {
    for (int j = i * 2; j <= limit; j += i) {
        divisorSums[j] += i;
    }
}
int sumAmicable = 0;
for (int n = 1; n <= limit; ++n) {
    int m = divisorSums[n];
    if (m != n && m <= limit && divisorSums[m] == n) {
        sumAmicable += n;
    }
}
return sumAmicable;
}