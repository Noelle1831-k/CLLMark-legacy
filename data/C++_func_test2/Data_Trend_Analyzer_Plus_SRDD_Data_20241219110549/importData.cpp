bool DataImporter::importData(const string& filePath) {
    cout << "Importing data from Excel file: " << filePath << "..." << endl;
    try {
        xlnt::workbook workbook;
        workbook.load(filePath);
        xlnt::worksheet sheet = workbook.active_sheet();
        for (auto row : sheet.rows(false)) {
            vector<string> rowData;
            for (auto cell : row) {
                rowData.push_back(cell.to_string());
            }
            data.push_back(rowData);
        }
        cout << "Data import completed successfully." << endl;
        return true;
    } catch (const exception& e) {
        cerr << "Error importing data: " << e.what() << endl;
        return false;
    }
}