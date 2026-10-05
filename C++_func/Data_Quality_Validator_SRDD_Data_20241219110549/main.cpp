int main() {
    DataValidator validator;
    cout << "Welcome to the Data Quality Validator!" << endl;
    string filePath;
    cout << "Enter the path of the dataset file to validate: ";
    cin >> filePath;
    validator.loadData(filePath);
    validator.validateData();
    validator.reportResults();
    cout << "Data validation process completed successfully." << endl;
    return 0;
}