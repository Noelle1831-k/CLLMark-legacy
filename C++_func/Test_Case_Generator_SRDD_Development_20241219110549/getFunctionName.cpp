string CodeParser::getFunctionName(const string& codeSnippet) {
    size_t start = codeSnippet.find(' ');
    size_t end = codeSnippet.find('(');
    if (start != string::npos && end != string::npos && end > start) {
        return codeSnippet.substr(start + 1, end - start - 1);
    }
    return "";
}