int countWithOddSetbits(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int setBits = 0;
        int num = i;
        while (num > 0) {
            setBits += num & 1;
            num >>= 1;
        }
        if (setBits % 2 != 0) {
            count++;
        }
    }
    return count;
}