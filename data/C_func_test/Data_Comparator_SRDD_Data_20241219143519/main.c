int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }
    DataSet *dataSet1 = importData(argv[1]);
    DataSet *dataSet2 = importData(argv[2]);
    if (dataSet1 == NULL || dataSet2 == NULL) {
        printf("Error importing data.\n");
        return 1;
    }
    ComparisonResult *result = compareDataSets(dataSet1, dataSet2);
    if (result == NULL) {
        printf("Error comparing data sets.\n");
        return 1;
    }
    generateReport(result);
    freeDataSet(dataSet1);
    freeDataSet(dataSet2);
    freeComparisonResult(result);
    return 0;
}