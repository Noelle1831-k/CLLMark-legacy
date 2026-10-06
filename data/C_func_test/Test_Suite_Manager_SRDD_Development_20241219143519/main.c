int main() {
    int option;
    printf("Welcome to the Test Suite Manager Application\n");
    printf("Initializing system...\n\n");
    initialize_test_suites(); 
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        option = get_integer_input();
        handle_menu_option(option);
        if (option == 6) break; 
    }
    cleanup_resources(); 
    return 0;
}