void simulate_turn(GameEngine *engine) {
    printf("\n--- Turn %d ---\n", ++engine->turn);
    if (engine->turn % 3 == 0) {
        printf("Random Event: Harvest Festival! +50 food\n");
        add_resources(&engine->civilization->resources, 50, 0, 0);
    }
    engine->civilization->population += 1;
    print_civilization_status(engine->civilization);
}