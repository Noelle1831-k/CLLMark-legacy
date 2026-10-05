const char* uniqueElement(int arr[], int n) {
    int firstElement = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] != firstElement) {
            return "NO";
        }
    }
    return "YES";
}