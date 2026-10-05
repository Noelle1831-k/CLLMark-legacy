vector<string> DataSet::getColumnData(size_t columnIndex) const {
    vector<string> columnData;
    for (const auto& row : data) {
        if (columnIndex < row.size()) {
            columnData.push_back(row[columnIndex]);
        }
    }
    return columnData;
}