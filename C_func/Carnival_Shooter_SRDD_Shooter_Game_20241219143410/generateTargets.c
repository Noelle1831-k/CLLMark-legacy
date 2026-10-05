void generateTargets(int level) {
    printf("Generating targets for Level %d...\n", level);
    for (int i = 0; i < targetsInLevel; i++) {
        createTarget(level);
    }
}