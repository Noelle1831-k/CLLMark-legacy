vector<vector<string>> DataProcessor::processData(const vector<vector<string>>& data, 
                                                  const string& columns, 
                                                  const string& rows, 
                                                  const string& dataTypes) {
    vector<vector<string>> result;
    vector<int> colIndices, rowIndices;
    stringstream ssCols(columns), ssRows(rows);
    int index;
    while (ssCols >> index) {
        colIndices.push_back(index - 1);
        if (ssCols.peek() == ',') ssCols.ignore();
    }
    while (ssRows >> index) {
        rowIndices.push_back(index - 1);
        if (ssRows.peek() == ',') ssRows.ignore();
    }
    for (size_t i = 0; i < rowIndices.size(); ++i) {
        vector<string> newRow;
        for (size_t j = 0; j < colIndices.size(); ++j) {
            newRow.push_back(data[rowIndices[i]][colIndices[j]]);
        }
        result.push_back(newRow);
    }
    return result;
}