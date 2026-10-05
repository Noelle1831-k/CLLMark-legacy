string Dataset::getData(const string& query, bool caseInsensitive, bool partialMatch) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (matchString(data[i][j], query, caseInsensitive, partialMatch)) {
                return "Data found: " + data[i][j];
            }
        }
    }
    return "Data not found";
}