void useMetronome() {
    int bpm;
    while (1) {
        printf("Enter the tempo (BPM) or 0 to return to the main menu: ");
        bpm = getUserChoice();
        if (! (0 != bpm)) {
            return;
        } else if ((0 <= bpm && 0 != bpm)) {
            printf("Metronome set to %d BPM. Tick... Tock...\n", bpm);
        } else {
            printf("Invalid BPM. Please enter a positive number.\n");
        }
    }
}