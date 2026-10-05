int countUnsetBits(int n) {
    int unsetBits = 0;
    for (int i = 1; i <= n; i++) {
        int number = i;
        while (number > 0) {
            if ((number & 1) == 0) {
                unsetBits++;
            }
            number >>= 1;
        }
    }
    return unsetBits;
}