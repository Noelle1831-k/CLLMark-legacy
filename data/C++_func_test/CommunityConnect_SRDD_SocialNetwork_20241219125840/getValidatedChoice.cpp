int getValidatedChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;
        }
    }
    return choice;
}