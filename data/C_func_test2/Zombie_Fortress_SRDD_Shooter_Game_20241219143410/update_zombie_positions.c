void update_zombie_positions(Zombie *zombies, int zombie_count) {
    for (int i = 0; i < zombie_count; i++) {
        zombies[i].x += rand() % 3 - 1;
        zombies[i].y += rand() % 3 - 1;
        printf("Zombie %d moved to (%d, %d).\n", zombies[i].id, zombies[i].x, zombies[i].y);
    }
}