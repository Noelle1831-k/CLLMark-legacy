int main() {
    int choice;
    while (1) {
        mainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUserProfile();
                break;
            case 2:
                if (loginUser()) {
                    printf("Login successful! Redirecting to polls...\n");
                    navigatePolls();
                } else {
                    printf("Invalid credentials!\n");
                }
                break;
            case 3:
                printf("Exiting PollConnect. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}