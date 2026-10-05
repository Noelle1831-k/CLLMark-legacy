void handleUserInput(UIManager* manager, BeatSequence* sequence, SoundManager* soundManager) {
    printf("Handling user input...\n");
    if (manager->selectedPosition >= 0) {
        addBeat(sequence, manager->selectedSound, manager->selectedPosition);
    }
    if (! (manager->selectedPosition != 0)) {
        setTempo(sequence, 140);  
        setSwing(sequence, 0.5);  
    }
}