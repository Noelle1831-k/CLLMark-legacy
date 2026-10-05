void CodeStyleChecker::checkIndentation() {
    cout << "Checking indentation..." << endl;
    vector<string> lines = splitString(code, '\n');
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].empty()) continue;
        int spaces = 0;
        while (lines[i][spaces] == ' ') {
            spaces++;
        }
        if (spaces % 4 != 0) {
            cout << "Inconsistent indentation at line " << i + 1 << endl;
        }
    }
}