int main() {
    cout << "Welcome to the Data Matcher Application!" << endl;
    DataSet dataset1, dataset2;
    DataMatcher matcher;
    FileManager fileManager;
    string file1, file2, exportFile;
    vector<string> fields;
    cout << "Enter the path for the first dataset: ";
    cin >> file1;
    dataset1.importData(file1);
    cout << "Enter the path for the second dataset: ";
    cin >> file2;
    dataset2.importData(file2);
    int numFields;
    cout << "Enter the number of fields to match: ";
    cin >> numFields;
    fields.resize(numFields);
    for (int i = 0; i < numFields; i++) {
        cout << "Enter field " << i + 1 << ": ";
        cin >> fields[i];
    }
    matcher.matchData(dataset1, dataset2, fields);
    vector<vector<string>> matchedRecords = matcher.getMatchedRecords();
    cout << "Matched Records: " << matchedRecords.size() << endl;
    for (const auto& record : matchedRecords) {
        for (const auto& field : record) {
            cout << field << " ";
        }
        cout << endl;
    }
    cout << "Enter the file name to export matched records: ";
    cin >> exportFile;
    fileManager.exportData(exportFile, matchedRecords);
    cout << "Export completed. Thank you for using the Data Matcher!" << endl;
    return 0;
}