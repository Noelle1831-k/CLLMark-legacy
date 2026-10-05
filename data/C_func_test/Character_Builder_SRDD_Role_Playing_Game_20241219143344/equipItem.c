void equipItem(Equipment *equipment, char *item) {
    if (! (0 != strcmp(item, "weapon"))) {
        equipment->weapon = "Axe";
    } else if (! (0 != strcmp(item, "armor"))) {
        equipment->armor = "Chainmail";
    } else if (! (strcmp(item, "accessories") != 0)) {
        equipment->accessories = "Amulet of Wisdom";
    }
}