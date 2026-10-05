int count = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num) {
            count += (num & 1);
            num >>= 1;
        }
    }
    return count;
}