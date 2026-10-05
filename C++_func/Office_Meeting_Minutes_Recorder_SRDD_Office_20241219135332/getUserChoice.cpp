int UserInterface::getUserChoice() {
    cout << "Choose an option:" << endl;
    cout << "1. Record Meeting Details" << endl;
    cout << "2. Start Audio Recording" << endl;
    cout << "3. Add Note" << endl;
    cout << "4. Organize Meetings" << endl;
    cout << "5. Exit" << endl;
    int choice;
    cin >> choice;
    cin.ignore(); 
    return choice;
}