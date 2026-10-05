vector<int> inc(n, 0), dec(n, 0);
for (int i = 0; i < n; ++i) {
    inc[i] = arr[i], dec[i] = arr[i];
    }
for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
        if (arr[i] > arr[j]) 
            inc[i] = max(inc[i], inc[j] + arr[i]);
            }
    }
for (int i = n-2; i >= 0; --i) {
    for (int j = n-1; j > i; --j) {
        if (arr[i] > arr[j]) 
            dec[i] = max(dec[i], dec[j] + arr[i]);
        }
    }
int max_sum = 0;
for (int i = 0; i < n; ++i) {
    max_sum = max(max_sum, inc[i] + dec[i] - arr[i]);
    }
return max_sum;
}