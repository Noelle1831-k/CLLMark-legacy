void check_collision(Player *players, Zombie *zombies, int zombie_count) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        for (int j = 0; j < zombie_count; j++) {
            if (players[i].x == zombies[j].x && players[i].y == zombies[j].y) {
                players[i].health -= 10;
                zombies[j].health -= players[i].weapon.damage;
                printf("Collision detected between Player %d and Zombie %d.\n", players[i].id, zombies[j].id);
                if (zombies[j].health <= 0) {
                    printf("Zombie %d defeated!\n", zombies[j].id);
                    zombies[j] = zombies[zombie_count - 1];
                    zombie_count--;
                }
            }
        }
    }
}