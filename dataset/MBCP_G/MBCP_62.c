int smallestNum(int arr[], int size) {
    if (size <= 0) return INT_MAX; 
    int smallest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}