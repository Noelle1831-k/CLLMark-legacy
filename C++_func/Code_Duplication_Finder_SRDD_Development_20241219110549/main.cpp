int main() {
    FileReader fileReader;
    CodeAnalyzer codeAnalyzer;
    DuplicateHighlighter duplicateHighlighter;
    ReportGenerator reportGenerator;
    vector<string> files = fileReader.readFiles("source_directory");
    vector<string> duplicates = codeAnalyzer.analyzeCode(files);
    duplicateHighlighter.highlightDuplicates(duplicates);
    reportGenerator.generateReport(duplicates);
    return 0;
}