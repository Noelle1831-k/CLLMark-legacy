int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <source_file>" << endl;
        return 1;
    }
    string filePath = argv[1];
    FileAnalyzer fileAnalyzer;
    CodeAnalyzer codeAnalyzer;
    ReportGenerator reportGenerator;
    vector<string> lines = fileAnalyzer.loadFile(filePath);
    vector<string> issues = codeAnalyzer.analyze(lines);
    reportGenerator.generateReport(issues);
    return 0;
}