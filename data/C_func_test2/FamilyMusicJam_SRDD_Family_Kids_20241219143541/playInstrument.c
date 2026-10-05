void playInstrument() {
    int instrumentChoice;
    while (1) {
        printf("\n--- Choose an Instrument ---\n");
        printf("1. Keyboard\n");
        printf("2. Drums\n");
        printf("3. Guitar\n");
        printf("4. Go Back to Main Menu\n");
        instrumentChoice = getUserChoice();
        switch (instrumentChoice) {
            case 1:
                printf("Playing the keyboard...\n");
                break;
            case 2:
                printf("Playing the drums...\n");
                break;
            case 3:
                printf("Playing the guitar...\n");
                break;
            case 4:
                return;
            default:
                printf("Invalid instrument choice. Please try again.\n");
        }
    }
}