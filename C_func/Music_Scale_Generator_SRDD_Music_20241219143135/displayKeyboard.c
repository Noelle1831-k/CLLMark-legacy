void displayKeyboard(char scaleNotes[]) {
    printf("Displaying scale on virtual keyboard: ");
    for (int i = 0; scaleNotes[i] != '\0'; i++) {
        printf("%c ", scaleNotes[i]);
    }
    printf("\n");
}