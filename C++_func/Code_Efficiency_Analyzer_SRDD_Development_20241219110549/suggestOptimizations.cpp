void OptimizationSuggester::suggestOptimizations(const char* code) {
    printf("Suggesting optimizations...\n");
    if (strstr(code, "a += i") != NULL) {
        printf("Optimization Suggestion: Use the formula for the sum of integers instead of a loop.\n");
        printf("You can replace the loop with: 'int sum = (n * (n - 1)) / 2;'\n");
    }
    if (strstr(code, "for") != NULL && strstr(code, "int i = 0; i < 10") != NULL) {
        printf("Optimization Suggestion: Consider making the loop more general or dynamic rather than hardcoding values.\n");
    }
    if (strstr(code, "for") != NULL && strstr(code, "int") != NULL) {
        printf("Optimization Suggestion: Consider using algorithms with logarithmic or constant time complexity, such as binary search or hash maps, if applicable.\n");
    }
}