map<int, int> primeCount;
for (int i = 2; i <= sqrt(n); i++) {
    while (n % i == 0) {
        primeCount[i]++;
        n /= i;
    }
}
if (n > 1) primeCount[n]++;
return primeCount.size();
}