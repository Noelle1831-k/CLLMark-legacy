bool greaterSpecificnum(int *list, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (list[i] > num) {
            return true;
        }
    }
    return false;
}