void generate_report(AnalysisResult *result) {
    printf("Expense Analysis Report:\n");
    printf("------------------------\n");
    for (int i = 0; i < result->count; i++) {
        printf("Category: %s, Potential Savings: $%.2f\n", result->categories[i], result->savings[i]);
    }
}