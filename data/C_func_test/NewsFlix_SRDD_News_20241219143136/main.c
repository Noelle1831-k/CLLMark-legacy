int main() {
    int choice;
    printf("\n=== Welcome to the Personalized News Application ===\n");
    printf("Your one-stop platform for curated news content.\n");
    if (!load_preferences()) {
        printf("Error: Failed to load preferences. Starting with default settings.\n");
    }
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handle_menu_choice(choice);
        if (choice == 5) {
            printf("Exiting the application. Goodbye!\n");
            break;
        }
    }
    save_preferences();
    return 0;
}