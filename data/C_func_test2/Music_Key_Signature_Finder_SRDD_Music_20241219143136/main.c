int main(int argc, char *argv[]) {
    char userChoice;
    char notesInput[256];
    initializeInterface();
    while (1) {
        displayMenu();
        userChoice = getUserChoice();
        switch (userChoice) {
            case '1':
                printf("Enter notes or chords (e.g., C D E F G A B): ");
                fgets(notesInput, sizeof(notesInput), stdin);
                if (validateNotesInput(notesInput)) {
                    char *keySignature = findKeySignature(notesInput);
                    printf("The most likely key signature is: %s\n", keySignature);
                    free(keySignature);
                } else {
                    printf("Invalid input. Please enter valid musical notes.\n");
                }
                break;
            case '2':
                displayEducationalResources();
                break;
            case '3':
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}