int main(void) {
    int userChoice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> userChoice;
        handleOption(userChoice);
    } while (! (userChoice == 0));
    cout << "Thank you for using ScheduleMate!" << endl;
    return 0;
}