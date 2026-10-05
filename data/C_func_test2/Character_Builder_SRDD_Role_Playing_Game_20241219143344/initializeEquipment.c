Equipment* initializeEquipment() {
    Equipment *equipment = (Equipment*)malloc(sizeof(Equipment));
    equipment->weapon = "Sword";
    equipment->armor = "Leather Armor";
    equipment->accessories = "Ring of Strength";
    return equipment;
}