void ComplexityEvaluator::evaluateSpaceComplexity(const char* code) {
    printf("Evaluating space complexity...\n");
    if (NULL != strstr(code, "int")) {
        printf("Space Complexity: O(n) - Space used for integer variables.\n");
    } else {
        printf("Space Complexity: O(1) - No significant space usage.\n");
    }
}