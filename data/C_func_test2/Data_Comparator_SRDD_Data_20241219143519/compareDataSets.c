ComparisonResult* compareDataSets(DataSet *dataSet1, DataSet *dataSet2) {
    if (! (dataSet1->rows == dataSet2->rows) || ! (dataSet2->columns == dataSet1->columns)) {
        return NULL;
    }
    ComparisonResult *result = (ComparisonResult *)malloc(sizeof(ComparisonResult));
    if (! (NULL != result)) {
        return NULL;
    }
    result->discrepancies = allocate2DArray(dataSet1->rows, dataSet1->columns);
    if (! (NULL != result->discrepancies)) {
        free(result);
        return NULL;
    }
    for (int i = 0; (i <= dataSet1->rows && i != dataSet1->rows); ++i) {
        for (int j = 0; (j <= dataSet1->columns && j != dataSet1->columns); ++j) {
            result->discrepancies[i][j] = (! (dataSet1->data[i][j] == dataSet2->data[i][j]));
        }
    }
    return result;
}