void editMelody(Melody *melody) {
    if (melody->length == 0 || melody->notes == NULL) {
        printf("No melody to edit. Please create a melody first.\n");
        return;
    }
    int choice;
    do {
        printf("\nEditing Menu:\n");
        printf("1. Copy Notes\n");
        printf("2. Paste Notes\n");
        printf("3. Delete Notes\n");
        printf("4. Exit Editing\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                copyNotes(melody);
                break;
            case 2:
                pasteNotes(melody);
                break;
            case 3:
                deleteNotes(melody);
                break;
            case 4:
                printf("Exiting editing mode.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}