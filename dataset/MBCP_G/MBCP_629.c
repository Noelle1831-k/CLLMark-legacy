void split(int list[], int size, int result[], int *result_size) {
    *result_size = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] % 2 == 0) {
            result[*result_size] = list[i];
            (*result_size)++;
        }
    }
}