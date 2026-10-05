vector<vector<string>> ExcelHandler::readExcel(const string& filename) {
    vector<vector<string>> data;
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();
    for (auto row : ws.rows(false)) {
        vector<string> rowData;
        for (auto cell : row) {
            rowData.push_back(cell.to_string());
        }
        data.push_back(rowData);
    }
    return data;
}