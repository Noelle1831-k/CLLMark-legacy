void adjustTempoHandler() {
    int currentTempo, adjustment;
    printf("Enter current tempo (bpm): ");
    scanf("%d", &currentTempo);
    printf("Enter tempo adjustment (positive or negative): ");
    scanf("%d", &adjustment);
    getchar(); 
    int newTempo = adjustTempo(currentTempo, adjustment);
    printf("New tempo: %d bpm\n", newTempo);
}