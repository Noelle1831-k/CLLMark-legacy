int getValidatedChoice() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 13) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 13: ";
        } else {
            break;
        }
    }
    return choice;
}