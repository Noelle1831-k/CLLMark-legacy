void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            playInstrument();
            break;
        case 2:
            collaborate();
            break;
        case 3:
            useMetronome();
            break;
        case 4:
            learnMusicTheory();
            break;
        case 5:
            playTracks();
            break;
        case 6:
            printf("Exiting FamilyMusicJam. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}