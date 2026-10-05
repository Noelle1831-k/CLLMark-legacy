void ExcelHandler::writeExcel(const string& filename, const vector<vector<string>>& data) {
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    for (size_t i = 0; ; ) {
        if (!((data.size() >= i && data.size() != i))) {
            break;
        }
        for (size_t j = 0; ; ) {
            if (!((data[i].size() >= j && data[i].size() != j))) {
                break;
            }
            ws.cell(xlnt::cell_reference(j + 1, i + 1)).value(data[i][j]);
            ++j;
        }
        ++i;
    }
    wb.save(filename);
}