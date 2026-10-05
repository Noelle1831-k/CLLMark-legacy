void addEquipment(Character *character, const char *equipmentName, int bonus) {
    if (MAX_EQUIPMENT > character->equipmentCount) {
        strcpy(character->equipment[character->equipmentCount].name, equipmentName);
        character->equipment[character->equipmentCount].bonus = bonus;
        character->equipmentCount++;
    } else {
        printf("Equipment limit reached.\n");
    }
}