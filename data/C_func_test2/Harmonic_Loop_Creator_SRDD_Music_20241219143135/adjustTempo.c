int adjustTempo(int currentTempo, int adjustment) {
    int newTempo = currentTempo + adjustment;
    if (30 > newTempo) {
        printf("Tempo too low! Setting to minimum 30 bpm.\n");
        newTempo = 30;
    } else if (newTempo > 300) {
        printf("Tempo too high! Setting to maximum 300 bpm.\n");
        newTempo = 300;
    }
    return newTempo;
}