void Dashboard::run() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter file path to load data: ";
                {
                    string filePath;
                    cin >> filePath;
                    loader.loadCSV(filePath);
                    rawData = loader.getData();
                    if (!rawData.empty()) {
                        isDataLoaded = true;
                        cout << "Data loaded successfully!" << endl;
                    } else {
                        cout << "Data loading failed. Please check the file path or format." << endl;
                    }
                }
                break;
            case 2:
                if (isDataLoaded) {
                    cout << "Enter filter condition (e.g., specific value in column 1): ";
                    {
                        string condition;
                        cin >> condition;
                        filteredData = processor.filterData(rawData, condition);
                        if (!filteredData.empty()) {
                            cout << "Data filtered successfully!" << endl;
                        } else {
                            cout << "No data matched the condition." << endl;
                        }
                    }
                } else {
                    cout << "Please load data first!" << endl;
                }
                break;
            case 3:
                if (!filteredData.empty()) {
                    cout << "Enter column index for aggregation (0-based): ";
                    {
                        int columnIndex;
                        cin >> columnIndex;
                        aggregatedData = processor.aggregateData(filteredData, columnIndex);
                        if (!aggregatedData.empty()) {
                            cout << "Data aggregated successfully!" << endl;
                        } else {
                            cout << "Aggregation failed. Please check the column index." << endl;
                        }
                    }
                } else {
                    cout << "Please filter data first!" << endl;
                }
                break;
            case 4:
                if (!aggregatedData.empty()) {
                    visualizer.generateBarChart(aggregatedData);
                } else {
                    cout << "Please aggregate data first!" << endl;
                }
                break;
            case 5:
                resetData();
                cout << "Data has been reset. You can start fresh!" << endl;
                break;
            case 6:
                cout << "Exiting the application..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}