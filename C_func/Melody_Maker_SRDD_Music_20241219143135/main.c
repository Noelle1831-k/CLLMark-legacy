int main() {
    printf("Welcome to Melody Maker!\n");
    Melody *melody = createMelody();
    loadLibrary();
    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Create Melody\n");
        printf("2. Edit Melody\n");
        printf("3. Play Melody\n");
        printf("4. Select Musical Style\n");
        printf("5. Select Instrument\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createMelodySequence(melody);
                break;
            case 2:
                editMelody(melody);
                break;
            case 3:
                playMelody(melody);
                break;
            case 4:
                selectStyle();
                break;
            case 5:
                selectInstrument();
                break;
            case 6:
                printf("Exiting Melody Maker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    freeMelody(melody);
    return 0;
}