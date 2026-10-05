Civilization *initialize_civilization(const char *name) {
    Civilization *civilization = (Civilization *)malloc(sizeof(Civilization));
    strcpy(civilization->name, name);
    civilization->population = 10;
    civilization->resources.food = 100;
    civilization->resources.gold = 50;
    civilization->resources.wood = 75;
    civilization->buildings = NULL;
    civilization->building_count = 0;
    return civilization;
}