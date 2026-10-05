int main() {
    initialize_data();
    int choice = 0;
    while (1) {
        display_main_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (choice == 6) {
            exit_application();
            break;
        }
        handle_user_selection(choice);
    }
    return 0;
}