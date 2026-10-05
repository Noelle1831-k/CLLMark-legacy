void exportToJSON(const TestCase *testCases) {
    FILE *file = fopen("testcases.json", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for JSON export.\n");
        return;
    }
    fprintf(file, "[\n");
    for (int i = 0; i < 5; ++i) {
        fprintf(file, "  {\n");
        fprintf(file, "    \"input\": [\"%s\", \"%s\"],\n", testCases[i].inputValues[0], testCases[i].inputValues[1]);
        fprintf(file, "    \"expectedOutput\": \"%s\"\n", testCases[i].expectedOutput);
        fprintf(file, "  }%s\n", (i < 4) ? "," : "");
    }
    fprintf(file, "]\n");
    fclose(file);
}