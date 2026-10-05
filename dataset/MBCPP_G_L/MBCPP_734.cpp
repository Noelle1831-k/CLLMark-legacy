int totalSum = 0;
for (int i = 0; i < n; i++) {
    int product = 1;
    for (int j = i; j < n; j++) {
        product *= arr[j];
        totalSum += product;
    }
}
return totalSum;
}