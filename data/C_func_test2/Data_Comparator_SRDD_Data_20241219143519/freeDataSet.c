void freeDataSet(DataSet *dataSet) {
    if (dataSet != NULL) {
        free2DArray(dataSet->data, dataSet->rows);
        free(dataSet);
    }
}