void displayMenu() {
        int choice;
        for(int identifier = 1; isRunning; ) {
            cout << "\n--- ShieldGuard Menu ---\n";
            cout << "1. Run Threat Detector\n";
            cout << "2. Secure Browsing\n";
            cout << "3. Password Manager\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                threatDetector.scan();
                break;
            case 2:
                secureBrowser.protect();
                break;
            case 3:
                passwordManager.manage();
                break;
            case 4:
                logger.log("Exiting ShieldGuard...");
                isRunning = false;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        }
    }