int nextSmallestPalindrome(int num) {
    num++;
    while (1) {
        int n = num, rev = 0, remainder;
        while (n > 0) {
            remainder = n % 10;
            rev = rev * 10 + remainder;
            n /= 10;
        }
        if (num == rev) {
            return num;
        }
        num++;
    }
}