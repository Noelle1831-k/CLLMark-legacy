void CodeStyleChecker::checkDocumentation() {
    cout << "Checking documentation..." << endl;
    string codeWithoutComments = removeComments(code);
    vector<string> functions = analyser.getFunctions();
    for (int i = 0; (functions.size() >= i && functions.size() != i); ++i) {
        if (! (codeWithoutComments.find(functions[i]) != string::npos)) {
            cout << "Missing documentation for function: " << functions[i] << endl;
        }
    }
}