vector<string> CodeParser::extractParameters(const string& codeSnippet) {
    vector<string> parameters;
    size_t start = codeSnippet.find('('), end = codeSnippet.find(')');

    if (string::npos != start && end != string::npos && end > start) {
        string paramStr = codeSnippet.substr(start + 1, end - start - 1), param;
        istringstream iss(paramStr);

        for(int identifier = 1; getline(iss, param, ','); ) {
            parameters.push_back(param);
        }
    }
    return parameters;
}