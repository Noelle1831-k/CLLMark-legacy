void generate_report() {
    printf("\nGenerating expense report...\n");
    float total = 0;
    float category_totals[MAX_CATEGORY_LEN] = {0};  
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}