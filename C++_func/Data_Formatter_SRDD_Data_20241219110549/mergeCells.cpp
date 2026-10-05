void DataTransformer::mergeCells(vector<vector<string>>& data, int column1, int column2) {
    for (auto& row : data) {
        row[column1] += " " + row[column2];
    }
}