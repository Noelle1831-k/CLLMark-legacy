int main() {
    initialize_system();
    int user_choice;
    while (1) {
        display_menu();  
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        handle_user_choice(user_choice);
    }
    return 0;
}