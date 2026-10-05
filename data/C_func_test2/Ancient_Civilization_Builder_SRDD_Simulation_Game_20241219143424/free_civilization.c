void free_civilization(Civilization *civilization) {
    for (int i = 0; i < civilization->building_count; i++) {
        free_building(civilization->buildings[i]);
    }
    free(civilization->buildings);
    free(civilization);
}