sort(arr.begin(), arr.end());
int minDiff = INT_MAX;
for(int i = 1; i < n; i++) {
    minDiff = min(minDiff, arr[i] - arr[i - 1]);
}
return minDiff;
}