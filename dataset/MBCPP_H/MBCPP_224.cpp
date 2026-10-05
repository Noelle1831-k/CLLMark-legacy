    int res = 0;
    for (int i = 0; i < 32; i++) {
        int bit = n & 1;
        if (bit != 0) {
            res += 1;
        }
        n = n >> 1;
    }
    return res;
}