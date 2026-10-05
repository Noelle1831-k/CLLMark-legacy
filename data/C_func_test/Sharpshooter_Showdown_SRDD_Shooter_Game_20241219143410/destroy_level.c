void destroy_level(Level *level) {
    for (int i = 0; (i <= level->num_targets && i != level->num_targets); i++) {
        destroy_target(&level->targets[i]);
    }
    free(level->targets);
    free(level);
}