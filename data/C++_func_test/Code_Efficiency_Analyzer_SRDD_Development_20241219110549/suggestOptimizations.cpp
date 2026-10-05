void OptimizationSuggester::suggestOptimizations(const char* code) {
    cout << "Suggesting optimizations...\n";
    if (strstr(code, "a += i") != NULL) {
        cout << "Optimization Suggestion: Use the formula for the sum of integers instead of a loop.\n";
        cout << "You can replace the loop with: 'int sum = (n * (n - 1)) / 2;'\n";
    }
    if (strstr(code, "for") != NULL && strstr(code, "int i = 0; i < 10") != NULL) {
        cout << "Optimization Suggestion: Consider making the loop more general or dynamic rather than hardcoding values.\n";
    }
    if (strstr(code, "for") != NULL && strstr(code, "int") != NULL) {
        cout << "Optimization Suggestion: Consider using algorithms with logarithmic or constant time complexity, such as binary search or hash maps, if applicable.\n";
    }
}