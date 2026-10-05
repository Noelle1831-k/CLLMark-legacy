    int i = 0;
    for (int v : nums) {
        if (v != i + 1) {
            return i;
        }
        i++;
    }
    return -1;
}