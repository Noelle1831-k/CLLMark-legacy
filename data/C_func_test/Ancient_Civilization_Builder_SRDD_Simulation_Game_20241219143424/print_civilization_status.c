void print_civilization_status(Civilization *civilization) {
    printf("\nCivilization: %s\n", civilization->name);
    printf("Population: %d\n", civilization->population);
    printf("Resources - Food: %d, Gold: %d, Wood: %d\n", civilization->resources.food,
           civilization->resources.gold, civilization->resources.wood);
    printf("Buildings (%d):\n", civilization->building_count);
    for (int i = 0; i < civilization->building_count; i++) {
        printf("  - %s (Level: %d)\n", civilization->buildings[i]->name,
               civilization->buildings[i]->level);
    }
}