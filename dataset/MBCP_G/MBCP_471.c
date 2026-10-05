int findRemainder(int arr[], int lens, int n) {
    long long product = 1;
    for(int i = 0; i < lens; i++) {
        product = (product * arr[i]) % n;
    }
    return product % n;
}