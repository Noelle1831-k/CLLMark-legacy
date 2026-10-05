void CodeAnalyzer::analyzeCode(const string& code) {
    cyclomaticComplexity.calculateComplexity(code);
    nestingDepth.calculateDepth(code);
    codeDuplication.detectDuplication(code);
    refactoringSuggestions.suggestRefactoring(code);
}