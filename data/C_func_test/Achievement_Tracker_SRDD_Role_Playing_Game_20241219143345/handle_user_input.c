void handle_user_input(AchievementManager *manager) {
    int choice;
    char buffer[256];
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter achievement details (name, description, category, tags, deadline, reward):\n");
                fgets(buffer, sizeof(buffer), stdin);
                add_achievement(manager, buffer);
                break;
            case 2:
                printf("Enter achievement ID to update:\n");
                fgets(buffer, sizeof(buffer), stdin);
                update_achievement(manager, atoi(buffer));
                break;
            case 3:
                printf("Enter achievement ID to mark as complete:\n");
                fgets(buffer, sizeof(buffer), stdin);
                mark_achievement_complete(manager, atoi(buffer));
                break;
            case 4:
                printf("Progress:\n");
                get_progress(manager);
                break;
            case 5:
                printf("Enter category name:\n");
                fgets(buffer, sizeof(buffer), stdin);
                list_achievements_by_category(manager, buffer);
                break;
            case 6:
                printf("Enter tag:\n");
                fgets(buffer, sizeof(buffer), stdin);
                list_achievements_by_tag(manager, buffer);
                break;
            case 7:
                printf("Enter achievement ID and reminder time:\n");
                fgets(buffer, sizeof(buffer), stdin);
                set_reminder(manager, buffer);
                break;
            case 8:
                printf("Exiting application...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}