int main() {
    vector<Meeting> meetings;
    vector<Employee> employees;
    meetings.emplace_back("Team Sync", "2023-12-18", vector<string>{"Alice", "Bob"});
    employees.emplace_back(101, "Alice");
    employees.emplace_back(102, "Bob");
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                handleEmployee(meetings, employees);
                break;
            case 2:
                handleManager(meetings);
                break;
            case 3:
                cout << "Exiting the application..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);
    return 0;
}