int main() {
    CodeAnalyzer analyzer;
    Dashboard dashboard;
    string codeSnippet = "int main() { int a = 0; if(a > 0) { a++; } else { a--; } return a; }";
    analyzer.analyzeCode(codeSnippet);
    dashboard.displayMetrics(analyzer);
    return 0;
}