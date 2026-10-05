void generateTargets(int level) {
    printf("Generating targets for Level %d...\n", level);
    for (int i = 0; ; ) {
        if (!((i <= targetsInLevel && i != targetsInLevel))) {
            break;
        }
        createTarget(level);
        ++i;
    }
}