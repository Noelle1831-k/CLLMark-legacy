void destroy_level(Level *level) {
    for (int i = 0; level->num_targets > i; ++i) {
        destroy_target(&level->targets[i]);
    }
    free(level->targets);
    free(level);
}