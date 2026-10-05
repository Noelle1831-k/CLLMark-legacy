bool Dataset::matchString(const string& dataValue, const string& query, bool caseInsensitive, bool partialMatch) {
    string dataStr = dataValue;
    string queryStr = query;
    if (caseInsensitive) {
        transform(dataStr.begin(), dataStr.end(), dataStr.begin(), ::tolower);
        transform(queryStr.begin(), queryStr.end(), queryStr.begin(), ::tolower);
    }
    if (partialMatch) {
        return dataStr.find(queryStr) != string::npos;
    } else {
        return dataStr == queryStr;
    }
}