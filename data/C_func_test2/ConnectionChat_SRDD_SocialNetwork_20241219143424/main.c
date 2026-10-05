int main() {
    int choice;
    initDatabase(); 
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            handleInvalidInput();
            continue;
        }
        getchar(); 
        switch (choice) {
            case 1:
                createProfile();
                break;
            case 2:
                listProfiles();
                break;
            case 3:
                searchUsers();
                break;
            case 4:
                startChat();
                break;
            case 5:
                shareFile();
                break;
            case 6:
                saveDatabase(); 
                printf("Exiting application. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}