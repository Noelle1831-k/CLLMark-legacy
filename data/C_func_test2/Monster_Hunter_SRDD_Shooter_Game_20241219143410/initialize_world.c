void initialize_world(World *world) {
    printf("Initializing world...\n");
    world->area_count = INITIAL_AREAS;
    for (int i = 0; i < world->area_count; i++) {
        snprintf(world->areas[i], AREA_NAME_LENGTH, "Area %d", i + 1);
    }
    printf("World initialized with %d areas.\n", world->area_count);
}