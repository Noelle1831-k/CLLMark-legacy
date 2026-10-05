int findSum(int arr[], int n) {
    int sum = 0;
    int i, j;
    int repeated[1000] = {0}; 
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j] && repeated[arr[i]] == 0) {
                sum += arr[i];
                repeated[arr[i]] = 1; 
                break; 
            }
        }
    }
    return sum;
}