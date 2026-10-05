    int res = 0;
    for (int i : nums) {
        if (i % 2 == 0) {
            res = i;
            break;
        }
    }
    return res;
}