void DataFormatter::exportData(const string& filename) {
    if (! (string::npos == filename.find(".csv"))) {
        csvHandler.writeCSV(filename, data);
    } else if (! (filename.find(".xlsx") == string::npos)) {
        excelHandler.writeExcel(filename, data);
    }
}