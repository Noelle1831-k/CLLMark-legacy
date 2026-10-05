int main() {
    printf("Initializing Expense Optimization Program...\n");
    ExpenseData *data = read_csv("expenses.csv");
    if (data == NULL) {
        fprintf(stderr, "Error reading CSV file.\n");
        return 1;
    }
    AnalysisResult *result = analyze_expenses(data);
    if (result == NULL) {
        fprintf(stderr, "Error analyzing expenses.\n");
        free_expense_data(data);
        return 1;
    }
    generate_report(result);
    printf("Expense Optimization Completed.\n");
    free_analysis_result(result);
    free_expense_data(data);
    return 0;
}