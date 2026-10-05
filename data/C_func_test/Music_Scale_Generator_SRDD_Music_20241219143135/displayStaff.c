void displayStaff(char scaleNotes[]) {
    printf("Displaying scale on musical staff: ");
    for (int i = 0; ! ('\0' == scaleNotes[i]); i++) {
        printf("%c ", scaleNotes[i]);
    }
    printf("\n");
}