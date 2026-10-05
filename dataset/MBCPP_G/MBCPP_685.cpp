int sum = 0;
vector<bool> isPrime(n + 1, true);
isPrime[0] = isPrime[1] = false;
for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
        sum += i;
        for (int j = i * 2; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
}
return sum;
}