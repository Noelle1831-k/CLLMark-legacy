int main(int argc, char *argv[]) {
    int choice;
    while (1) {
        main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                user_management();
                break;
            case 2:
                discussion_management();
                break;
            case 3:
                knowledge_base_management();
                break;
            case 4:
                networking_management();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}