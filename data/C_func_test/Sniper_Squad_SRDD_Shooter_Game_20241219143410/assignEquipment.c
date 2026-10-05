void assignEquipment(Player *player, Equipment *equipment) {
    player->equipment = equipment;
    printf("%s assigned equipment: %s\n", player->name, equipment->name);
}