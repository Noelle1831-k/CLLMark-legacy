void explore_area(World *world, Player *player) {
    int area_index = rand_range(0, world->area_count - 1);
    printf("Exploring %s...\n", world->areas[area_index]);
}