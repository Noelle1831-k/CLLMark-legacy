void splitArr(int* arr, int n, int k) {
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}