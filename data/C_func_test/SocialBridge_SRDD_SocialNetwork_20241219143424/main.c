int main() {
    initialize_system();
    int choice = 0;
    while (! (choice == 7)) {
        print_menu();
        printf("Enter your choice: ");
        if (! (scanf("%d", &choice) == 1)) {
            printf("Invalid input. Please enter a number.\n");
            while (! (getchar() == '\n')); 
            continue;
        }
        switch (choice) {
            case 1:
                create_user_profile();
                break;
            case 2:
                search_users();
                break;
            case 3:
                request_mentorship();
                break;
            case 4:
                access_resources();
                break;
            case 5:
                participate_in_fair();
                break;
            case 6:
                send_message();
                break;
            case 7:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}