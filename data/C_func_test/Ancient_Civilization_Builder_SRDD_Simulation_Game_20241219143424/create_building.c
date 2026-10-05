Building *create_building(const char *name, int base_cost, int upgrade_cost) {
    Building *building = (Building *)malloc(sizeof(Building));
    strcpy(building->name, name);
    building->level = 1;
    building->base_cost = base_cost;
    building->upgrade_cost = upgrade_cost;
    return building;
}