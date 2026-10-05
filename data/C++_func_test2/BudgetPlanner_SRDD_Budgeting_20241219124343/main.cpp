int main() {
    cout << "Welcome to BudgetPlanner - Manage Your Finances Effectively!" << endl;
    User user;
    FileHandler fileHandler;
    BudgetPlanner planner;
    user.setUserDetails();
    while (true) {
        displayMainMenu();
        handleMainMenu(planner, fileHandler);
    }
    return 0;
}