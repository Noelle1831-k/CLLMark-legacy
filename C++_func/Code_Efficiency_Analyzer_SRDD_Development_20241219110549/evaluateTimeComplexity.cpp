void ComplexityEvaluator::evaluateTimeComplexity(const char* code) {
    printf("Evaluating time complexity...\n");
    if (strstr(code, "for") != NULL) {
        printf("Time Complexity: O(n) - Linear time complexity due to a loop.\n");
    } else {
        printf("Time Complexity: O(1) - Constant time complexity.\n");
    }
}