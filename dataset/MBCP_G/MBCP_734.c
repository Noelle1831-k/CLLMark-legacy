int sumOfSubarrayProd(int arr[], int n) {
    int sum = 0;
    for (int start = 0; start < n; start++) {
        long long product = 1;
        for (int end = start; end < n; end++) {
            product *= arr[end];
            sum += product;
        }
    }
    return sum;
}