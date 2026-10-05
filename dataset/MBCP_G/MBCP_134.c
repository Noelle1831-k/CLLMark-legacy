const char* checkLast(int arr[], int n, int p) {
    int lastElement = arr[n - 1];
    if (p % 2 == 0) {
        return (lastElement % 2 == 0) ? "EVEN" : "ODD";
    } else {
        return "ODD";
    }
}