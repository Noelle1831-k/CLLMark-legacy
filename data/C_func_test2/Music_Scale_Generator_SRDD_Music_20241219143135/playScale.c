void playScale(char scaleNotes[]) {
    printf("Playing scale: ");
    for (int i = 0; scaleNotes[i] != '\0'; i++) {
        printf("%c ", scaleNotes[i]);
    }
    printf("\n");
}