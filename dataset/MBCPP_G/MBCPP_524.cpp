vector<int> msis(arr);
for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
            msis[i] = msis[j] + arr[i];
        }
    }
}
return *max_element(msis.begin(), msis.end());
}