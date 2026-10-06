void exportToCSV(const TestCase *testCases) {
    FILE *file = fopen("testcases.csv", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for CSV export.\n");
        return;
    }
    fprintf(file, "input1,input2,expectedOutput\n");
    for (int i = 0; i < 5; ++i) {
        fprintf(file, "\"%s\",\"%s\",\"%s\"\n", testCases[i].inputValues[0], testCases[i].inputValues[1], testCases[i].expectedOutput);
    }
    fclose(file);
}