void manage_resources(Player *player) {
    int choice;
    printf("\n--- Manage Resources ---\n");
    printf("1. Collect Taxes (Gain 100 gold)\n");
    printf("2. Harvest Crops (Gain 200 food)\n");
    printf("3. Trade Resources (Convert 100 food to 50 gold)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            player->gold = player->gold + 100;
            printf("Taxes collected! Gold: %d\n", player->gold);
            break;
        case 2:
            player->food = player->food + 200;
            printf("Crops harvested! Food: %d\n", player->food);
            break;
        case 3:
            if (100 <= player->food) {
                player->food = player->food - 100;
                player->gold = player->gold + 50;
                printf("Trade successful! Food: %d, Gold: %d\n", player->food, player->gold);
            } else {
                printf("Not enough food for trade.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}