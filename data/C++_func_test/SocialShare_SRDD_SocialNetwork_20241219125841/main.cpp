int main(void) {
    SocialNetwork app;
    int choice = 0;
    printf("Welcome to SocialShare!\n");
    while (true) {
        printf("\nMenu:\n1. Register\n2. Login\n3. Explore Content\n4. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        switch (choice) {
            case 1:
                app.registerUser();
                break;
            case 2:
                app.loginUser();
                break;
            case 3:
                app.exploreContent();
                break;
            case 4:
                printf("Exiting SocialShare. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}