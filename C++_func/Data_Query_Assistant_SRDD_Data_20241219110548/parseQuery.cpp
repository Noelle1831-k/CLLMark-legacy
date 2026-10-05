void QueryProcessor::parseQuery(const string& query) {
    stringstream ss(query);
    string token;
    caseInsensitive = false;
    partialMatch = false;
    while (ss >> token) {
        if (token == "case-insensitive") {
            caseInsensitive = true;
        } else if (token == "partial-match") {
            partialMatch = true;
        } else {
            parsedQuery = token;
        }
    }
}