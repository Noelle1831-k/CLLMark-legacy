    int max = 0;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 1;
        for (int j = i; j < arr.size(); j++) {
            sum *= arr[j];
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}