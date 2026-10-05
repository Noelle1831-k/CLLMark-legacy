int main(int argc, char *argv[]) {
    int choice;
    Schedule schedule;
    Notification notification;
    while (true) {
        printf("=====================\n");
        printf("Financial Scheduler\n");
        printf("=====================\n");
        printf("1. Add Transaction\n");
        printf("2. Display Schedule\n");
        printf("3. Display Calendar\n");
        printf("4. Send Notifications\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                string type, description, date;
                printf("Enter amount: ");
                cin >> amount;
                printf("Enter type (income/expense): ");
                cin >> type;
                printf("Enter description: ");
                cin.ignore();
                getline(cin, description);
                printf("Enter date (YYYY-MM-DD): ");
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
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}