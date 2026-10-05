    for(int i = 0; i < arrSize; i++) {
        if(i == 0 || arr[i] % 2 != 0) {
            continue;
        }
        arr[i] = arr[i - 1];
    }
    return arr[arrSize - 1];
}