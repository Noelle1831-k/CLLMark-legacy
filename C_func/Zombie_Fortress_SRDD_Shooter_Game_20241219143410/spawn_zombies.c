void spawn_zombies(Zombie *zombies, int *zombie_count, int max_zombies) {
    for (int i = 0; i < max_zombies; i++) {
        zombies[i].id = i;
        zombies[i].health = 50;
        zombies[i].x = rand() % 100;
        zombies[i].y = rand() % 100;
        (*zombie_count)++;
        printf("Zombie %d spawned at (%d, %d).\n", i, zombies[i].x, zombies[i].y);
    }
}