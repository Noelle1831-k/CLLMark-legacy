int count_true(bool *lst, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (lst[i]) {
            count++;
        }
    }
    return count;
}