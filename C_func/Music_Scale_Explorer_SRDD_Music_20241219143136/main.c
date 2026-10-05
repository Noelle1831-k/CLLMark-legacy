int main() {
    int user_choice;
    initialize_app();
    while (1) {
        display_menu();
        printf("Your choice: ");
        scanf("%d", &user_choice);
        getchar(); 
        handle_user_input(user_choice);
    }
    return 0;
}