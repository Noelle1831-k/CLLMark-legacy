int equilibriumIndex(int arr[], int size) {
    int sum = 0; 
    int leftSum = 0; 
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    for (int i = 0; i < size; ++i) {
        sum -= arr[i]; 
        if (leftSum == sum) {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}
