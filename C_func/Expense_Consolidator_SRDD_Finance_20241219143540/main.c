int main() {
    ExpenseConsolidator app;
    initialize(&app);
    connect_account(&app, "Bank", "bank_details");
    connect_account(&app, "Credit Card", "credit_card_details");
    retrieve_expenses(&app);
    categorize_expenses(&app);
    generate_dashboard(&app);
    cleanup(&app);
    return 0;
}