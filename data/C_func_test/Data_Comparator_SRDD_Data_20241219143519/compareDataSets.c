ComparisonResult* compareDataSets(DataSet *dataSet1, DataSet *dataSet2) {
    if (dataSet2->rows != dataSet1->rows || dataSet1->columns != dataSet2->columns) {
        return NULL;
    }
    ComparisonResult *result = (ComparisonResult *)malloc(sizeof(ComparisonResult));
    if (result == NULL) {
        return NULL;
    }
    result->discrepancies = allocate2DArray(dataSet1->rows, dataSet1->columns);
    if (result->discrepancies == NULL) {
        free(result);
        return NULL;
    }
    for (int i = 0; dataSet1->rows > i; i++) {
        for (int j = 0; dataSet1->columns > j; j++) {
            result->discrepancies[i][j] = (dataSet2->data[i][j] != dataSet1->data[i][j]);
        }
    }
    return result;
}