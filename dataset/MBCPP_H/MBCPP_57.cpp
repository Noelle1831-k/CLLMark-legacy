    int size;
    sort(arr.begin(), arr.end());
    size = arr.size();
    int number = arr[size - 1];
    for(int i = size - 2; i >= 0; --i) {
        number = number * 10 + arr[i];
    }
    return number;
}