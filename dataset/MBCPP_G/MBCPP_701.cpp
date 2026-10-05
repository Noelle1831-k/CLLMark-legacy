int totalSum = accumulate(arr.begin(), arr.end(), 0);
int leftSum = 0;
for (int i = 0; i < arr.size(); i++) {
    totalSum -= arr[i];
    if (leftSum == totalSum) {
        return i;
    }
    leftSum += arr[i];
}
return -1;
}