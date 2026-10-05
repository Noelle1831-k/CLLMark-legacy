int main() {
    int user_choice;
    char username[50];
    printf("Welcome to the Language Conversation Partner App!\n");
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        switch (user_choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                login(username);
                break;
            case 2:
                printf("Enter username for registration: ");
                scanf("%s", username);
                register_user(username);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}