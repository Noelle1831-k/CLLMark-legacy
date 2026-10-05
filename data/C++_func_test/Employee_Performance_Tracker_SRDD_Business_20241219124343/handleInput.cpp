void Dashboard::handleInput() {
    int choice;
    cin >> choice;
    if (choice == 1) {
        int id;
        string name, dept;
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee Department: ";
        getline(cin, dept);
        employees.push_back(Employee(id, name, dept));
        cout << "Employee added successfully!" << endl;
    } else if (choice == 2) {
        string goal;
        cout << "Enter a performance goal: ";
        cin.ignore();
        getline(cin, goal);
        goalManager.setGoal(goal);
    } else if (choice == 3) {
        int id, score;
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Performance Score (0-100): ";
        cin >> score;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getEmployeeID() == id) {
                employees[i].updatePerformance(score);
                evaluationManager.evaluate(employees[i], score);
                break;
            }
        }
    } else if (choice == 4) {
        int id;
        string filename;
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter filename to save the report: ";
        cin >> filename;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getEmployeeID() == id) {
                reportManager.generateReport(employees[i]);
                reportManager.saveToFile(employees[i], filename);
                break;
            }
        }
    } else if (choice == 5) {
        cout << "Exiting the program." << endl;
        exit(0);
    } else {
        cout << "Invalid choice!" << endl;
    }
}