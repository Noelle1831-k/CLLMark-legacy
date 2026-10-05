void Expense::categorizeExpense() {
    cout << "Select category (1: Food, 2: Transport, 3: Entertainment, 4: Utilities, 5: Other): ";
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 5) {
        cout << "Invalid category. Please select a valid option: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (choice) {
        case 1: category = "Food"; break;
        case 2: category = "Transport"; break;
        case 3: category = "Entertainment"; break;
        case 4: category = "Utilities"; break;
        default: category = "Other"; break;
    }
}