void render_game(Player *players, Zombie *zombies, int zombie_count) {
    printf("Rendering game state...\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d at (%d, %d) with health %d.\n", players[i].id, players[i].x, players[i].y, players[i].health);
    }
    for (int i = 0; i < zombie_count; i++) {
        printf("Zombie %d at (%d, %d) with health %d.\n", zombies[i].id, zombies[i].x, zombies[i].y, zombies[i].health);
    }
}