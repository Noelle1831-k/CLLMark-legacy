vector<double> Dataset::getVariableData(int index) const {
    vector<double> variableData;
    for (const auto &row : data) {
        variableData.push_back(row[index]);
    }
    return variableData;
}