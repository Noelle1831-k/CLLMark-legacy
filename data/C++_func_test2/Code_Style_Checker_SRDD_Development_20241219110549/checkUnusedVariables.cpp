void CodeStyleChecker::checkUnusedVariables() {
    cout << "Checking unused variables..." << endl;
    vector<string> variables = analyser.getVariables();
    for (int i = 0; i < variables.size(); i++) {
        if (code.find(variables[i]) == string::npos) {
            cout << "Unused variable: " << variables[i] << endl;
        }
    }
}