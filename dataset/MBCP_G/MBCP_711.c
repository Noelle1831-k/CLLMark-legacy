bool productEqual(int n) {
    int oddProduct = 1, evenProduct = 1;
    int position = 1;
    while (n > 0) {
        int digit = n % 10;
        if (position % 2 == 0) {
            evenProduct *= digit;
        } else {
            oddProduct *= digit;
        }
        n /= 10;
        position++;
    }
    return oddProduct == evenProduct;
}