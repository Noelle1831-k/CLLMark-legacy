int main() {
    vector<Employee> employees;
    vector<Manager> managers;
    VacationCalendar vacationCalendar;
    NotificationSystem notificationSystem;
    ReportGenerator reportGenerator;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                int empID;
                string startDate, endDate;
                cout << "Enter Employee ID: ";
                cin >> empID;
                cout << "Enter Start Date (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter End Date (YYYY-MM-DD): ";
                cin >> endDate;
                bool found = false;
                for (int i = 0; i < employees.size(); i++) {
                    if (employees[i].getEmployeeID() == empID) {
                        employees[i].submitVacationRequest(startDate, endDate, vacationCalendar, notificationSystem);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Employee not found!" << endl;
                }
                break;
            }
            case 2: {
                int empID;
                cout << "Enter Employee ID: ";
                cin >> empID;
                bool found = false;
                for (int i = 0; i < employees.size(); i++) {
                    if (employees[i].getEmployeeID() == empID) {
                        employees[i].viewVacationStatus();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Employee not found!" << endl;
                }
                break;
            }
            case 3: {
                int mgrID;
                cout << "Enter Manager ID: ";
                cin >> mgrID;
                bool found = false;
                for (int i = 0; i < managers.size(); i++) {
                    if (managers[i].getManagerID() == mgrID) {
                        managers[i].viewRequests(vacationCalendar, notificationSystem);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Manager not found!" << endl;
                }
                break;
            }
            case 4: {
                vacationCalendar.displayCalendar();
                break;
            }
            case 5: {
                reportGenerator.generateReport(vacationCalendar);
                break;
            }
            case 6: {
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 6);
    return 0;
}