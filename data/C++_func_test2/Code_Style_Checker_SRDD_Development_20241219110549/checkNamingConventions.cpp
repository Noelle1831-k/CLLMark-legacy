void CodeStyleChecker::checkNamingConventions() {
    cout << "Checking naming conventions..." << endl;
    vector<string> functions = analyser.getFunctions();
    for (int i = 0; i < functions.size(); i++) {
        if (!isCamelCase(functions[i])) {
            cout << "Incorrect naming convention for function: " << functions[i] << endl;
        }
    }
}