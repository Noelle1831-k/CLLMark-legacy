void run_game(GameEngine *engine) {
    while (engine->current_level < engine->total_levels) {
        Level *level = engine->levels[engine->current_level];
        printf("\n--- Starting Level %d ---\n\n", level->level_number);
        while (!is_level_completed(level)) {
            display_grid(level->grid);
            printf("\nActions:\n");
            printf("1. Place Block\n");
            printf("2. Remove Block\n");
            printf("3. Hint\n");
            printf("4. Rotate Block\n");
            printf("5. Exit\n");
            printf("Choose an action: ");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    place_block_ui(level->grid);
                    break;
                case 2:
                    remove_block_ui(level->grid);
                    break;
                case 3:
                    generate_hint(engine->hint_system, level);
                    break;
                case 4:
                    printf("Enter block ID to rotate: ");
                    int block_id, angle;
                    scanf("%d", &block_id);
                    printf("Enter rotation angle (90/180/270): ");
                    scanf("%d", &angle);
                    rotate_block_by_id(level->grid, block_id, angle);
                    break;
                case 5:
                    printf("Exiting game...\n");
                    return;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
        printf("\n--- Level %d Completed! ---\n\n", level->level_number);
        engine->current_level++;
    }
    printf("Congratulations! You've completed all levels!\n");
}