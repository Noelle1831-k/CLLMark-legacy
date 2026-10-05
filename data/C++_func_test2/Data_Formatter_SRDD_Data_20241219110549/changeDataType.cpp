void DataTransformer::changeDataType(vector<vector<string>>& data, int column, const string& newType) {
    for (auto& row : data) {
        if (newType == "int") {
            row[column] = to_string(stoi(row[column]));
        }
    }
}