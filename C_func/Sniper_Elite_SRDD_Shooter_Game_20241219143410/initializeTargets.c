void initializeTargets(int numTargets) {
    for (int i = 0; i < numTargets; i++) {
        targets[i].x = generateRandomDouble(0.0, 100.0);
        targets[i].y = generateRandomDouble(0.0, 100.0);
        targets[i].intelligenceValue = rand() % 100;
        printf("Target %d initialized at (%.2f, %.2f) with intelligence value %d.\n", i, targets[i].x, targets[i].y, targets[i].intelligenceValue);
    }
}