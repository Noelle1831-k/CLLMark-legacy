void organize_outreach_event(Game* game) {
    printf("Organizing community outreach event...\n");
    printf("1. Social Media Campaign\n");
    printf("2. Local Event\n");
    printf("3. School Visit\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Social media campaign launched! Community support increased.\n");
            game->community_support += 10;
            break;
        case 2:
            printf("Local event held successfully! Gained donations and volunteers.\n");
            game->funds += 500;
            game->volunteers += 2;
            break;
        case 3:
            printf("Visited local school! Awareness about adoption raised.\n");
            game->community_support += 15;
            break;
        default:
            printf("Invalid choice.\n");
    }
}