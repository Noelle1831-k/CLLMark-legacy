void MoneyTracker::run() {
    int choice;
    do {
        std::cout << "1. Add Transaction\n2. View Reports\n3. Set Budget Goals\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewReports();
                break;
            case 3:
                setBudgetGoals();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);
}