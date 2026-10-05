int swaps = 0, onesCount = 0;
for (int i = 0; i < n; ++i)
    if (arr[i] == 1) onesCount++;
int left = 0, right = 0, count1 = 0;
while (right < onesCount) {
    if (arr[right] == 1) count1++;
    right++;
}
int minSwaps = onesCount - count1;
while (right < n) {
    if (arr[right] == 1) count1++;
    if (arr[left] == 1) count1--;
    minSwaps = min(minSwaps, onesCount - count1);
    left++;
    right++;
}
return minSwaps;
}