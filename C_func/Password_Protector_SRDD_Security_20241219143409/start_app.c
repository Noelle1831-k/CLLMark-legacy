void start_app() {
    char choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        choice = getchar();
        getchar(); 
        handle_user_input(choice);
    }
}