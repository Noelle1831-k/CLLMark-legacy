void listSports() {
    if (sportCount == 0) {
        printf("No sports available.\n");
        return;
    }
    printf("Available sports:\n");
    for (int i = 0; i < sportCount; i++) {
        printf("%d. %s\n", i + 1, sports[i]);
    }
}