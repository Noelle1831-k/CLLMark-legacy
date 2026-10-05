int** allocate2DArray(int rows, int columns) {
    int **array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(columns * sizeof(int));
        if (array[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}