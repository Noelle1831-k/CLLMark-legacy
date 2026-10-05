Level* create_level(int level_number) {
    Level *level = (Level*)malloc(sizeof(Level));
    level->level_number = level_number;
    level->num_targets = level_number * 5 + 5;  
    level->targets = (Target*)malloc(sizeof(Target) * level->num_targets);
    for (int i = 0; i < level->num_targets; i++) {
        level->targets[i] = create_target(level_number);  
    }
    return level;
}