void equipItem(Equipment *equipment, char *item) {
    if (strcmp(item, "weapon") == 0) {
        equipment->weapon = "Axe";
    } else if (strcmp(item, "armor") == 0) {
        equipment->armor = "Chainmail";
    } else if (strcmp(item, "accessories") == 0) {
        equipment->accessories = "Amulet of Wisdom";
    }
}