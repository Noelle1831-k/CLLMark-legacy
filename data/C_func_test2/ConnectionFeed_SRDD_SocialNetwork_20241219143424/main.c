int main() {
    initialize_system();
    while (app_running) {
        display_menu();
        handle_user_input();
    }
    return 0;
}