int main() {
    ConnectHive hiveSystem;
    int choice;
    while(true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch(choice) {
            case 1:
                hiveSystem.viewUsers();
                break;
            case 2:
                hiveSystem.addUser();
                break;
            case 3:
                hiveSystem.addItemToMarket();
                break;
            case 4:
                hiveSystem.removeItemFromMarket();
                break;
            case 5:
                hiveSystem.viewMarketplace();
                break;
            case 6:
                cout << "Exiting ConnectHive...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}