int main() {
    string codeSnippet;
    cout << "Enter the function signature or code snippet: ";
    getline(cin, codeSnippet);
    CodeParser parser;
    vector<string> parameters = parser.extractParameters(codeSnippet);
    string functionName = parser.getFunctionName(codeSnippet);
    TestGenerator generator;
    vector<TestCase> basicCases = generator.generateBasicCases(codeSnippet);
    vector<TestCase> edgeCases = generator.generateEdgeCases(codeSnippet);
    vector<TestCase> complexCases = generator.generateComplexCases(codeSnippet);
    vector<TestCase> allCases = basicCases;
    allCases.insert(allCases.end(), edgeCases.begin(), edgeCases.end());
    allCases.insert(allCases.end(), complexCases.begin(), complexCases.end());
    ExportManager exporter;
    string outputJSON = "test_cases.json";
    string outputCSV = "test_cases.csv";
    exporter.exportToJSON(allCases, outputJSON);
    exporter.exportToCSV(allCases, outputCSV);
    cout << "Test cases successfully generated and exported." << endl;
    cout << "JSON File: " << outputJSON << endl;
    cout << "CSV File: " << outputCSV << endl;
    return 0;
}