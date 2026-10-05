int main() {
    int choice;
    printf("Welcome to PhotoScrapBook!\n");
    while (1) {
        display_menu();
        printf("Choose an option (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }
        if (choice == 6) {
            exit_program();
            break;
        }
        handle_option(choice);
    }
    return 0;
}