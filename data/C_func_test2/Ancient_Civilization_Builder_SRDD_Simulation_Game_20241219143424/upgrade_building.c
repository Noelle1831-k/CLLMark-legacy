void upgrade_building(Building *building) {
    building->level++;
    printf("Building %s upgraded to Level %d!\n", building->name, building->level);
}