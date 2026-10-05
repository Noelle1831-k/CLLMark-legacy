vector<string> DataSet::getColumnData(size_t columnIndex) const {
    vector<string> columnData;
    for (const auto& row : data) {
        if (row.size() > columnIndex) {
            columnData.push_back(row[columnIndex]);
        }
    }
    return columnData;
}