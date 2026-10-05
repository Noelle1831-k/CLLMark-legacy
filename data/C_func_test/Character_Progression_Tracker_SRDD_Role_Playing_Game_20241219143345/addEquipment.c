void addEquipment(Character *character, const char *equipmentName, int bonus) {
    if ((character->equipmentCount <= MAX_EQUIPMENT && character->equipmentCount != MAX_EQUIPMENT)) {
        strcpy(character->equipment[character->equipmentCount].name, equipmentName);
        character->equipment[character->equipmentCount].bonus = bonus;
        character->equipmentCount++;
    } else {
        printf("Equipment limit reached.\n");
    }
}