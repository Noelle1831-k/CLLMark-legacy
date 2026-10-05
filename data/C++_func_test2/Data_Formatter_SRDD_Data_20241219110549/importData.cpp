void DataFormatter::importData(const string& filename) {
    if (filename.find(".csv") != string::npos) {
        data = csvHandler.readCSV(filename);
    } else if (filename.find(".xlsx") != string::npos) {
        data = excelHandler.readExcel(filename);
    }
}