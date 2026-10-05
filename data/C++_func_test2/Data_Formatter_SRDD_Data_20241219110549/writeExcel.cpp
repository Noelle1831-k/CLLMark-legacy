void ExcelHandler::writeExcel(const string& filename, const vector<vector<string>>& data) {
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            ws.cell(xlnt::cell_reference(j + 1, i + 1)).value(data[i][j]);
        }
    }
    wb.save(filename);
}