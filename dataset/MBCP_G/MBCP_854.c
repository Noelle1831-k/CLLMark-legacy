void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
void rawHeap(int rawheap[], int n) {
    buildMaxHeap(rawheap, n);
}
int main() {
    int arr1[] = {25, 44, 68, 21, 39, 23, 89};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    rawHeap(arr1, n1);
    int arr2[] = {25, 35, 22, 85, 14, 65, 75, 25, 58};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    rawHeap(arr2, n2);
    int arr3[] = {4, 5, 6, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    rawHeap(arr3, n3);
    return 0;
}
