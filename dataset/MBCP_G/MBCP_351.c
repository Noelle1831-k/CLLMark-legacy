int firstElement(int arr[], int n, int k) {
    int count[1000] = {0}; 
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] == k) {
            return arr[i];
        }
    }
    return -1; 
}