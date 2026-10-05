int main() {
    DataImporter dataImporter;
    Visualizer visualizer;
    Customizer customizer;
    Exporter exporter;
    int choice;
    cout << "Welcome to the Data Visualizer!" << endl;
    cout << "Importing data..." << endl;
    dataImporter.importData();
    while (true) {
        cout << "\nChoose a visualization type:" << endl;
        cout << "1. Bar Chart" << endl;
        cout << "2. Line Graph" << endl;
        cout << "3. Scatter Plot" << endl;
        cout << "4. Pie Chart" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                visualizer.createBarChart();
                break;
            case 2:
                visualizer.createLineGraph();
                break;
            case 3:
                visualizer.createScatterPlot();
                break;
            case 4:
                visualizer.createPieChart();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }
        cout << "Customizing visualization..." << endl;
        customizer.customizeAppearance();
        cout << "Choose export format:" << endl;
        cout << "1. Export as Image" << endl;
        cout << "2. Export as Link" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Exporting as image by default." << endl;
            clearInputBuffer();
            exporter.exportAsImage();
            continue;
        }
        switch (choice) {
            case 1:
                exporter.exportAsImage();
                break;
            case 2:
                exporter.exportAsLink();
                break;
            default:
                cout << "Invalid choice. Exporting as image by default." << endl;
                exporter.exportAsImage();
        }
        cout << "Visualization complete!" << endl;
    }
}