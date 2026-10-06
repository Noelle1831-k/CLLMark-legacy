vector<string> CodeParser::extractParameters(const string& codeSnippet) {
    vector<string> parameters;
    size_t start = codeSnippet.find('(');
    size_t end = codeSnippet.find(')');
    if (start != string::npos && end != string::npos && end > start) {
        string paramStr = codeSnippet.substr(start + 1, end - start - 1);
        istringstream iss(paramStr);
        string param;
        while (getline(iss, param, ',')) {
            parameters.push_back(param);
        }
    }
    return parameters;
}