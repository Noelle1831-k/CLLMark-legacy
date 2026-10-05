int main() {
    int choice;
    char username[50];
    printf("Welcome to the Vocabulary Enhancement Application\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    load_progress(username);
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_vocab();
                break;
            case 2:
                quiz_user(username);
                break;
            case 3:
                display_progress(username);
                break;
            case 4:
                save_progress(username);
                printf("Progress saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}