Monster generate_monster() {
    Monster monster;
    monster.health = rand_range(50, 150);
    monster.attack_power = rand_range(10, 50);
    monster.loot_count = rand_range(1, MAX_MONSTER_LOOT);
    for (int i = 0; i < monster.loot_count; i++) {
        strncpy(monster.loot[i], generate_loot(), sizeof(monster.loot[i]) - 1);
        monster.loot[i][sizeof(monster.loot[i]) - 1] = '\0';  
    }
    printf("Monster generated successfully.\n");
    return monster;
}