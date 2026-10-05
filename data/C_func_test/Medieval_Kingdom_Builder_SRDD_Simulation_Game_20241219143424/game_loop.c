void game_loop() {
    Player player = initialize_player();
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_kingdom_status(&player);
                break;
            case 2:
                build_or_upgrade_structure(&player);
                break;
            case 3:
                manage_resources(&player);
                break;
            case 4:
                engage_diplomacy(&player);
                break;
            case 5:
                plan_warfare(&player);
                break;
            case 6:
                printf("Game saved (feature coming soon)!\n");
                break;
            case 7:
                printf("Exiting the game. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}