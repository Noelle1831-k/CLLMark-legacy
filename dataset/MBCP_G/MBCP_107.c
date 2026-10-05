int countHexadecimal(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (i >= 10 && i <= 15) {
            count++;
        }
    }
    return count;
}