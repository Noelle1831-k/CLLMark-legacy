void swapList(int *list, int size) {
    if (size > 1) {
        int temp = list[0];
        list[0] = list[size - 1];
        list[size - 1] = temp;
    }
}