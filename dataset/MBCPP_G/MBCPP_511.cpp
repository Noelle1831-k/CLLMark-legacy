int minSum = INT_MAX;
for (int i = 1; i <= sqrt(num); ++i) {
    if (num % i == 0) {
        int pairFactor = num / i;
        minSum = min(minSum, i + pairFactor);
    }
}
return minSum;
}