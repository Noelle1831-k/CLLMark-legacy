if (r > n) return 0;
    vector<int> fac(n+1, 1);
    for (int i = 2; i <= n; i++)
        fac[i] = fac[i-1] * i % p;
    int res = fac[n];
    res = res * pow(fac[r], p-2, p) % p;
    res = res * pow(fac[n-r], p-2, p) % p;
    return res;

int pow(int a, int b, int mod) {
    int result = 1;  
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}