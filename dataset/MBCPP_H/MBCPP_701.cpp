    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    int sum1 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (sum1 == sum - sum1 - arr[i]) {
            return i;
        }
        sum1 += arr[i];
    }
    return -1;
}