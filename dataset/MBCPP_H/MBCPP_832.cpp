    int max = 0;
    int num = 0;
    for (auto c : input) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (int) c - (int) '0';
        } else {
            if (num > max) {
                max = num;
            }
            num = 0;
        }
    }
    return max;
}