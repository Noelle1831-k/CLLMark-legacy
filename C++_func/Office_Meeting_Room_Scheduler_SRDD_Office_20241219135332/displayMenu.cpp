void Dashboard::displayMenu() {
    int choice;
    do {
        cout << "Office Meeting Room Scheduler" << endl;
        cout << "1. Add Room" << endl;
        cout << "2. Schedule Meeting" << endl;
        cout << "3. List Available Rooms" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        handleUserInput(choice);
    } while (choice != 4);
}