int isPalindrome(int num) {
    int original = num, reversed = 0, remainder;
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return original == reversed;
}
int largestPalindrome(int a[], int n) {
    int maxPalindrome = -1;
    for (int i = 0; i < n; i++) {
        if (isPalindrome(a[i])) {
            if (a[i] > maxPalindrome) {
                maxPalindrome = a[i];
            }
        }
    }
    return maxPalindrome;
}