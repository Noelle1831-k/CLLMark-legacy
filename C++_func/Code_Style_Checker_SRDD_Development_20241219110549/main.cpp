int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <source_code_file>" << endl;
        return 1;
    }
    string fileName = argv[1];
    string code = readFile(fileName);
    CodeStyleChecker checker(code);
    checker.checkIndentation();
    checker.checkUnusedVariables();
    checker.checkNamingConventions();
    checker.checkDocumentation();
    return 0;
}