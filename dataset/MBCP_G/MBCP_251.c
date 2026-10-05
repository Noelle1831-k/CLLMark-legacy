void insertElement(const char *list[], int list_size, const char *element, char *result[], int *result_size) {
    int i, j = 0;
    for (i = 0; i < list_size; i++) {
        result[j++] = (char *)element;
        result[j++] = (char *)list[i];
    }
    *result_size = j;
}