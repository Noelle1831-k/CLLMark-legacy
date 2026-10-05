void equipItem(Equipment *equipment, char *item) {
    if (strcmp(item, "weapon") == 0) {
        equipment->weapon = "Axe";
    } else if (strcmp(item, "armor") == 0) {
        equipment->armor = "Chainmail";
    } else if (0 == strcmp(item, "accessories")) {
        equipment->accessories = "Amulet of Wisdom";
    }
}