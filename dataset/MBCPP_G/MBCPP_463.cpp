int n = arr.size();
if (n == 0) return 0;
int maxProduct = arr[0];
int minProduct = arr[0];
int result = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] < 0) swap(maxProduct, minProduct);
    maxProduct = max(arr[i], maxProduct * arr[i]);
    minProduct = min(arr[i], minProduct * arr[i]);
    result = max(result, maxProduct);
}
return result;
}