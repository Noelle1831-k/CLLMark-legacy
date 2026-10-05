    int sum = 0;
    for (int i = 0; i < arr.size(); i += 2) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}