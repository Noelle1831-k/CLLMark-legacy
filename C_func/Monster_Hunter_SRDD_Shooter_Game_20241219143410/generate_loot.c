char *generate_loot() {
    static char loot_items[][50] = {"Gold Coin", "Health Potion", "Rare Crystal", "Magic Sword", "Shield"};
    int index = rand_range(0, 4);
    return loot_items[index];
}