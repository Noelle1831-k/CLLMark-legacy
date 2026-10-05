    int jumps = 0;
    int i = 0;
    while (i < arr.size() && jumps < n) {
        if (arr[i] == 0) {
            i++;
        } else {
            int j = i + arr[i];
            while (j < arr.size() && arr[j] == 0) {
                j++;
            }
            if (j == arr.size()) {
                i++;
            } else {
                jumps++;
                i = j;
            }
        }
    }
    return jumps;
}