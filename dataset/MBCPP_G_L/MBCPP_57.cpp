sort(arr.begin(), arr.end(), greater<int>());
int maxNum = 0;
for (int i = 0; i < n; i++) {
    maxNum = maxNum * 10 + arr[i];
}
return maxNum;
}