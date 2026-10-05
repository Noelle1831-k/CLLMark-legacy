void free2DArray(int **array, int rows) {
    if (array != NULL) {
        for (int i = 0; i < rows; i++) {
            free(array[i]);
        }
        free(array);
    }
}