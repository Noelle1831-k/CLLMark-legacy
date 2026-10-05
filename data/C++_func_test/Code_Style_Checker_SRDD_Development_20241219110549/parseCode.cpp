void CodeAnalyser::parseCode() {
    try {
        regex variableRegex(R"(\b(int|char|float|double|bool)\s+(\w+)\s*;)");
        regex functionRegex(R"(\b(\w+)\s+(\w+)\s*\([^)]*\)\s*\{)");
        regex classRegex(R"(\bclass\s+(\w+)\s*\{)");
        smatch match;
        string::const_iterator searchStart(code.cbegin());
        while (regex_search(searchStart, code.cend(), match, variableRegex)) {
            variables.push_back(match[2]);
            searchStart = match.suffix().first;
        }
        searchStart = code.cbegin();
        while (regex_search(searchStart, code.cend(), match, functionRegex)) {
            functions.push_back(match[2]);
            searchStart = match.suffix().first;
        }
        searchStart = code.cbegin();
        while (regex_search(searchStart, code.cend(), match, classRegex)) {
            classes.push_back(match[1]);
            searchStart = match.suffix().first;
        }
    } catch (const regex_error& e) {
        cerr << "Regex error: " << e.what() << endl;
    }
}