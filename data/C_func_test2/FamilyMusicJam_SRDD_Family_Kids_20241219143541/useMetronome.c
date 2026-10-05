void useMetronome() {
    int bpm;
    while (1) {
        printf("Enter the tempo (BPM) or 0 to return to the main menu: ");
        bpm = getUserChoice();
        if (bpm == 0) {
            return;
        } else if (bpm > 0) {
            printf("Metronome set to %d BPM. Tick... Tock...\n", bpm);
        } else {
            printf("Invalid BPM. Please enter a positive number.\n");
        }
    }
}