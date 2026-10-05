void removeItem(Equipment *equipment, char *item) {
    if (strcmp(item, "weapon") == 0) {
        equipment->weapon = "None";
    } else if (strcmp(item, "armor") == 0) {
        equipment->armor = "None";
    } else if (strcmp(item, "accessories") == 0) {
        equipment->accessories = "None";
    }
}