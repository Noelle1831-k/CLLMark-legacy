int main() {
    FileHandler fileHandler;
    string code = fileHandler.readCodeFromFile("sample_code.cpp");
    CodeAnalyzer analyzer;
    analyzer.analyzeSyntax(code);
    analyzer.analyzePerformance(code);
    analyzer.analyzeReadability(code);
    SuggestionGenerator suggestionGen;
    suggestionGen.generateOptimizationSuggestions();
    suggestionGen.generateReadabilitySuggestions();
    suggestionGen.generateMaintainabilitySuggestions();
    Report report;
    report.compileReport();
    report.displayReport();
    return 0;
}