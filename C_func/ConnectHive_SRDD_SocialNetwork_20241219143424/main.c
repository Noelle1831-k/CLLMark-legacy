int main() {
    int choice = 0;
    while (1) {
        display_main_menu();
        choice = validate_input();
        handle_user_choice(choice);
    }
    return 0;
}