void populate_enemies(Quest *quest) {
    int num_enemies = generate_random(3, 6);
    quest->enemy_count = num_enemies;
    for (int i = 0; i < num_enemies; i++) {
        sprintf(quest->enemies[i], "Enemy %d (Level %d)", i + 1, generate_random(1, 10));
    }
}