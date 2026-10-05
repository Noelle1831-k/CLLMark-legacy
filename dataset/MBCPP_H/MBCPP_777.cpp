    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1] && arr[i] != arr[i - 2] && arr[i] != arr[i - 3] && arr[i] != arr[i - 4] && arr[i] != arr[i - 5] && arr[i] != arr[i - 6] && arr[i] != arr[i - 7] && arr[i] != arr[i - 8] && arr[i] != arr[i - 9]) {
            sum += arr[i];
        }
    }
    return sum;
}