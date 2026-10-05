int findElement(int *arr, int arrSize, int ranges[][2], int rangesSize, int rotations, int index) {
    for (int i = 0; i < rotations; i++) {
        int start = ranges[i][0];
        int end = ranges[i][1];
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    return arr[index];
}