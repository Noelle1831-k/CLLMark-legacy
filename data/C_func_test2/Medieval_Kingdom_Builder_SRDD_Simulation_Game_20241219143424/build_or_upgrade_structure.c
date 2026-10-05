void build_or_upgrade_structure(Player *player) {
    int choice, cost;
    printf("\n--- Build or Upgrade Structures ---\n");
    printf("1. Castle (Cost: 500 gold, 200 materials)\n");
    printf("2. Farm (Cost: 300 gold, 100 materials)\n");
    printf("3. Market (Cost: 400 gold, 150 materials)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            cost = 500;
            if (player->gold >= cost && player->materials >= 200) {
                player->gold = player->gold - cost;
                player->materials = player->materials - 200;
                printf("Castle upgraded! Kingdom level increased.\n");
                player->kingdom_level++;
            } else {
                printf("Not enough resources.\n");
            }
            break;
        case 2:
            cost = 300;
            if (player->gold >= cost && player->materials >= 100) {
                player->gold = player->gold - cost;
                player->materials = player->materials - 100;
                printf("Farm upgraded! Food production increased.\n");
            } else {
                printf("Not enough resources.\n");
            }
            break;
        case 3:
            cost = 400;
            if (player->gold >= cost && player->materials >= 150) {
                player->gold = player->gold - cost;
                player->materials = player->materials - 150;
                printf("Market upgraded! Trade efficiency increased.\n");
            } else {
                printf("Not enough resources.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}