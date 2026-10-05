UserInterface* createUserInterface(ExpenseManager *expenseManager, CategoryManager *categoryManager) {
    UserInterface *ui = (UserInterface*)malloc(sizeof(UserInterface));
    ui->expenseManager = expenseManager;
    ui->categoryManager = categoryManager;
    return ui;
}