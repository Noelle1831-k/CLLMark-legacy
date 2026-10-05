int sameLength(int a, int b) {
    int countDigits(int n) {
        int count = 0;
        while (n != 0) {
            n /= 10;
            count++;
        }
        return count;
    }
    return countDigits(a) == countDigits(b);
}