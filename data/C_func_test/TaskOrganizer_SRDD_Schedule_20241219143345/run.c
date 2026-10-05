void run(TaskOrganizerApp *app) {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        handle_choice(app, choice);
    } while (! (choice == 0));
}