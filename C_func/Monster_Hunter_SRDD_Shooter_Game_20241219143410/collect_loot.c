void collect_loot(Player *player, Monster monster) {
    printf("Collecting loot from monster...\n");
    for (int i = 0; i < monster.loot_count; i++) {
        add_to_inventory(&(player->inventory), monster.loot[i]);
    }
    printf("Loot added to player's inventory.\n");
}