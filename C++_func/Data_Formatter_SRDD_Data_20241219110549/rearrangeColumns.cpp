void DataTransformer::rearrangeColumns(vector<vector<string>>& data, const vector<int>& newOrder) {
    for (auto& row : data) {
        vector<string> newRow(row.size());
        for (size_t i = 0; i < newOrder.size(); ++i) {
            newRow[i] = row[newOrder[i]];
        }
        row = newRow;
    }
}