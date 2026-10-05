void CodeAnalyzer::analyze(const char* code) {
    ComplexityEvaluator complexityEvaluator;
    OptimizationSuggester optimizationSuggester;
    printf("Analyzing code snippet...\n");
    complexityEvaluator.evaluateTimeComplexity(code);
    complexityEvaluator.evaluateSpaceComplexity(code);
    optimizationSuggester.suggestOptimizations(code);
}