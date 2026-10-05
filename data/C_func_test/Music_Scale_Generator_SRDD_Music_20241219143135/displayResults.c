void displayResults(char scaleNotes[]) {
    printf("Generated Scale Notes: ");
    for (int i = 0; scaleNotes[i] != '\0'; i++) {
        printf("%c ", scaleNotes[i]);
    }
    printf("\n");
}