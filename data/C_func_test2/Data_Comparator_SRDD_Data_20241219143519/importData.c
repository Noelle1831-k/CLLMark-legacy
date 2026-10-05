DataSet* importData(const char *filename) {
    DataSet *dataSet = (DataSet *)malloc(sizeof(DataSet));
    if (dataSet == NULL) {
        return NULL;
    }
    dataSet->rows = 100; 
    dataSet->columns = 10; 
    dataSet->data = allocate2DArray(dataSet->rows, dataSet->columns);
    if (dataSet->data == NULL) {
        free(dataSet);
        return NULL;
    }
    for (int i = 0; i < dataSet->rows; i++) {
        for (int j = 0; j < dataSet->columns; j++) {
            dataSet->data[i][j] = i * j; 
        }
    }
    return dataSet;
}