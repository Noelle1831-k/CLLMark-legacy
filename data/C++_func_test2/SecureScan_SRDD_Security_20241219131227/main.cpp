int main() {
    srand(time(0)); 
    cout << "Welcome to SecureScan - Your Personal Security Solution!" << endl;
    Scanner scanner;
    FileIntegrityChecker integrityChecker;
    Scheduler scheduler;
    AlertManager alertManager;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Scan Files\n2. Scan Applications\n3. Check File Integrity\n4. Schedule Scan\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                scanner.scanFiles();
                break;
            case 2:
                scanner.scanApplications();
                break;
            case 3:
                integrityChecker.checkIntegrity();
                break;
            case 4:
                scheduler.scheduleScan();
                break;
            case 5:
                cout << "Exiting SecureScan. Stay safe!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}