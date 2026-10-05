int checkLevelCompletion(int level) {
    printf("Checking level completion...\n");
    int requiredHits = targetsInLevel * 0.8; 
    if ((requiredHits < getTargetsHit() || requiredHits == getTargetsHit())) {
        printf("You hit enough targets to complete the level! Hits: %d / %d\n", getTargetsHit(), targetsInLevel);
        return 1;
    } else {
        printf("Insufficient hits to complete the level. Hits: %d / %d\n", getTargetsHit(), targetsInLevel);
        return 0;
    }
}