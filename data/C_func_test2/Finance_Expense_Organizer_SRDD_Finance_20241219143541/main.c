int main() {
    ExpenseManager *expenseManager = createExpenseManager();
    CategoryManager *categoryManager = createCategoryManager();
    UserInterface *ui = createUserInterface(expenseManager, categoryManager);
    runUserInterface(ui);
    destroyUserInterface(ui);
    destroyExpenseManager(expenseManager);
    destroyCategoryManager(categoryManager);
    return 0;
}