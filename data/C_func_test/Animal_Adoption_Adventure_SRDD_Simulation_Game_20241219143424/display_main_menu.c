void display_main_menu(Game* game) {
    printf("\nMain Menu:\n");
    printf("1. Manage Animals\n");
    printf("2. Fundraising\n");
    printf("3. Volunteer Management\n");
    printf("4. Community Outreach\n");
    printf("5. Exit Game\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Animal management selected.\n");
            manage_animals();
            break;
        case 2:
            printf("Fundraising selected.\n");
            conduct_fundraising(game);
            break;
        case 3:
            printf("Volunteer management selected.\n");
            manage_volunteers(game);
            break;
        case 4:
            printf("Community Outreach selected.\n");
            organize_outreach_event(game);
            break;
        case 5:
            game->is_running = 0;
            break;
        default:
            printf("Invalid choice. Try again.\n");
    }
}