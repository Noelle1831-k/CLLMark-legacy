void reverseArray(int *array, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}
void reverseListLists(int lists[][4], int listsSize, int *listColSize) {
    for (int i = 0; i < listsSize; i++) {
        reverseArray(lists[i], listColSize[i]);
    }
}