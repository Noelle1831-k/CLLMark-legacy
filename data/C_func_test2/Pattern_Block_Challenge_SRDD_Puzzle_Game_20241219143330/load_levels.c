int load_levels(GameEngine *engine) {
    engine->total_levels = 5; 
    engine->levels = (Level **)malloc(engine->total_levels * sizeof(Level *));
    if (!engine->levels) {
        printf("Error: Failed to allocate memory for levels.\n");
        return 0;
    }
    srand(time(NULL));
    for (int i = 0; i < engine->total_levels; i++) {
        engine->levels[i] = create_level(i + 1);
    }
    return 1; 
}