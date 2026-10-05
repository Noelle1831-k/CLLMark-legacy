void initializeEquipment(Equipment *equipment, const char *name, int power) {
    strncpy(equipment->name, name, sizeof(equipment->name));
    equipment->power = power;
}