void DataFormatter::exportData(const string& filename) {
    if (filename.find(".csv") != string::npos) {
        csvHandler.writeCSV(filename, data);
    } else if (filename.find(".xlsx") != string::npos) {
        excelHandler.writeExcel(filename, data);
    }
}