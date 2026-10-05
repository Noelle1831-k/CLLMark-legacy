if(n <= 1) return n;
int maxLen = 1;
int currLen = 1;
for(int i = 1; i < n; ++i) {
    if(abs(arr[i] - arr[i-1]) <= 1) {
        currLen++;
    } else {
        maxLen = max(maxLen, currLen);
        currLen = 1;
    }
}
maxLen = max(maxLen, currLen);
return maxLen;
}