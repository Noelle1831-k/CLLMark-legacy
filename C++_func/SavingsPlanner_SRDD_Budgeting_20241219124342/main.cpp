int main() {
    UserInterface ui;
    BudgetManager bm;
    SavingsTracker st;
    ReportGenerator rg;
    ui.displayWelcomeMessage();
    bm.loadIncomeData();
    bm.loadExpenseData();
    st.loadSavingsTarget();
    while (true) {
        int choice = ui.displayMenu();
        switch (choice) {
            case 1:
                bm.inputIncome();
                break;
            case 2:
                bm.inputExpense();
                break;
            case 3:
                st.setSavingsTarget();
                break;
            case 4:
                st.trackProgress();
                break;
            case 5:
                rg.generateReport();
                break;
            case 6:
                ui.displayExitMessage();
                return 0;
            default:
                ui.displayInvalidOptionMessage();
                break;
        }
    }
    return 0;
}