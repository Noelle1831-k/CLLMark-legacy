void rearrangeNumbs(int arr[], int n) {
    int i = -1;
    for (int j = 0; j < n; j++) {
        if (arr[j] > 0) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}