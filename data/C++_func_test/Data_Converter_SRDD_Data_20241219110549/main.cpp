int main(void) {
    Logger logger;
    logger.logInfo("Starting Data Converter Application...");
    printf("Welcome to Data Converter Application\n");
    printf("Select an input file format (CSV, JSON, XML, Excel): ");
    string inputFormat;
    scanf("%s", &inputFormat);
    printf("Enter the path to the input file: ");
    string inputFilePath;
    scanf("%s", &inputFilePath);
    FileManager fileManager;
    if (!fileManager.validateFile(inputFilePath)) {
        logger.logError("Invalid file path. Exiting application.");
        printf("Error: Invalid file path.\n");
        return 1;
    }
    printf("Select the output file format (CSV, JSON, XML, Excel): ");
    string outputFormat;
    scanf("%s", &outputFormat);
    printf("Enter the output file path: ");
    string outputFilePath;
    scanf("%s", &outputFilePath);
    DataProcessor dataProcessor;
    vector<vector<string>> data = fileManager.readFile(inputFilePath, inputFormat);
    if (data.empty()) {
        logger.logError("Failed to read data from the input file.");
        printf("Error: Failed to read data from the input file.\n");
        return 1;
    }
    printf("Specify columns to include (comma-separated, e.g., 1,2,3): ");
    string columns;
    scanf("%s", &columns);
    printf("Specify rows to include (comma-separated, e.g., 1,2,3): ");
    string rows;
    scanf("%s", &rows);
    printf("Specify new data types for columns (comma-separated, e.g., int,string): ");
    string dataTypes;
    scanf("%s", &dataTypes);
    vector<vector<string>> processedData = dataProcessor.processData(data, columns, rows, dataTypes);
    if (!fileManager.writeFile(outputFilePath, outputFormat, processedData)) {
        logger.logError("Failed to write data to the output file.");
        printf("Error: Failed to write data to the output file.\n");
        return 1;
    }
    printf("Data conversion completed successfully!\n");
    logger.logInfo("Data conversion completed successfully.");
    return 0;
}