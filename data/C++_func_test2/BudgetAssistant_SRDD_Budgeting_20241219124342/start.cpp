void start() {
        cout << "Welcome to BudgetAssistant!" << endl;
        fileManager.loadUserData(user);
        showMenu();
    }