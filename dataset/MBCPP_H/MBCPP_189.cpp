    int i = 0;
    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] > 0) {
            if (i == 0) {
                i = j;
            } else {
                if (arr[i] < 0) {
                    arr[i] = arr[j];
                }
                else {
                    i -= 1;
                }
            }
        }
    }
    return i;
}