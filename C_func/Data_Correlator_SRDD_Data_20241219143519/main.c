int main() {
    int user_choice;
    printf("Welcome to the Data Correlator Application!\n");
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &user_choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        if (user_choice == 0) {
            printf("Exiting the application. Goodbye!\n");
            break;
        }
        handle_user_choice(user_choice);
    }
    return 0;
}