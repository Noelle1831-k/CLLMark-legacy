    int max = 0;
    int count = 0;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 0;
        }
    }
    if (count > max) {
        max = count;
    }
    return max;
}