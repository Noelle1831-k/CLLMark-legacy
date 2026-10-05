int main() {
    Logger logger;
    logger.logInfo("Starting Data Converter Application...");
    cout << "Welcome to Data Converter Application" << endl;
    cout << "Select an input file format (CSV, JSON, XML, Excel): ";
    string inputFormat;
    cin >> inputFormat;
    cout << "Enter the path to the input file: ";
    string inputFilePath;
    cin >> inputFilePath;
    FileManager fileManager;
    if (!fileManager.validateFile(inputFilePath)) {
        logger.logError("Invalid file path. Exiting application.");
        cout << "Error: Invalid file path." << endl;
        return 1;
    }
    cout << "Select the output file format (CSV, JSON, XML, Excel): ";
    string outputFormat;
    cin >> outputFormat;
    cout << "Enter the output file path: ";
    string outputFilePath;
    cin >> outputFilePath;
    DataProcessor dataProcessor;
    vector<vector<string>> data = fileManager.readFile(inputFilePath, inputFormat);
    if (data.empty()) {
        logger.logError("Failed to read data from the input file.");
        cout << "Error: Failed to read data from the input file." << endl;
        return 1;
    }
    cout << "Specify columns to include (comma-separated, e.g., 1,2,3): ";
    string columns;
    cin >> columns;
    cout << "Specify rows to include (comma-separated, e.g., 1,2,3): ";
    string rows;
    cin >> rows;
    cout << "Specify new data types for columns (comma-separated, e.g., int,string): ";
    string dataTypes;
    cin >> dataTypes;
    vector<vector<string>> processedData = dataProcessor.processData(data, columns, rows, dataTypes);
    if (!fileManager.writeFile(outputFilePath, outputFormat, processedData)) {
        logger.logError("Failed to write data to the output file.");
        cout << "Error: Failed to write data to the output file." << endl;
        return 1;
    }
    cout << "Data conversion completed successfully!" << endl;
    logger.logInfo("Data conversion completed successfully.");
    return 0;
}