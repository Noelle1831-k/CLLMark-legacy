int main() {
    int choice;
    Schedule schedule;
    Notification notification;
    while (true) {
        cout << "=====================" << endl;
        cout << "Financial Scheduler" << endl;
        cout << "=====================" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. Display Schedule" << endl;
        cout << "3. Display Calendar" << endl;
        cout << "4. Send Notifications" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                string type, description, date;
                cout << "Enter amount: ";
                cin >> amount;
                cout << "Enter type (income/expense): ";
                cin >> type;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                FinancialTransaction transaction(amount, type, description, date);
                schedule.addTransaction(transaction);
                break;
            }
            case 2: {
                schedule.displaySchedule();
                break;
            }
            case 3: {
                Calendar calendar;
                calendar.displayCalendar(schedule);
                break;
            }
            case 4: {
                notification.sendNotifications(schedule);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}