int** multiList(int rownum, int colnum) {
    int** arr = (int**)malloc(rownum * sizeof(int*));
    for (int i = 0; i < rownum; i++) {
        arr[i] = (int*)malloc(colnum * sizeof(int));
        for (int j = 0; j < colnum; j++) {
            arr[i][j] = i * j;
        }
    }
    return arr;
}