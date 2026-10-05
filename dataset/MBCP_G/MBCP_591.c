void swapList(int* array, int size) {
    if (size > 1) {
        int temp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = temp;
    }
}