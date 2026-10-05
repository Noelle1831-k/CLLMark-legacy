bool validate(int n) {
    int freq[10] = {0};
    while (n > 0) {
        int digit = n % 10;
        freq[digit]++;
        n /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        if (freq[i] > i) {
            return false;
        }
    }
    return true;
}