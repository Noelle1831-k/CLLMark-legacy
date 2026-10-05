int main(int argc, char *argv[]) {
    printf("Welcome to ScheduleFocus: Stay Focused and Manage Your Time!\n");
    load_user_data();
    main_menu();
    save_user_data();
    return 0;
}