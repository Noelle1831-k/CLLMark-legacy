int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int modInverse(int a, int p) {
    int x, y;
    int g = gcdExtended(a, p, &x, &y);
    if (g != 1)
        return -1;
    else {
        int res = (x % p + p) % p;
        return res;
    }
}
int modularInverse(int arr[], int n, int p) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % p != 0) {
            int inv = modInverse(arr[i], p);
            if (inv == arr[i])
                count++;
        }
    }
    return count;
}