bool issortList(int list1[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (list1[i] > list1[i + 1]) {
            return false;
        }
    }
    return true;
}