void add_building(Civilization *civilization, Building *building) {
    civilization->buildings = (Building **)realloc(civilization->buildings, 
                        (civilization->building_count + 1) * sizeof(Building *));
    civilization->buildings[civilization->building_count] = building;
    civilization->building_count++;
}