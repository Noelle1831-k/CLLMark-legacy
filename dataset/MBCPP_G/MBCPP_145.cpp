int maxDiff = 0;
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        int diff = abs(arr[i] - arr[j]);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
}
return maxDiff;
}