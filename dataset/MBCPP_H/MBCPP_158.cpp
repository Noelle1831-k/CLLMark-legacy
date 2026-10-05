    int max1 = arr[n-1];
    int res = 0;
    for (int i = 0; i < n; i++) {
        if ((max1 - arr[i]) % k != 0) {
            return -1;
        } else {
            res += (max1 - arr[i]) / k;
        }
    }
    return res;
}