void countBloodTypes() {
    char line[20];
    int countA = 0, countB = 0, countAB = 0, countO = 0;
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *token = strtok(line, ",");
        token = strtok(NULL, "\n");
        if (strcmp(token, "A") == 0) {
            countA++;
        } else if (strcmp(token, "B") == 0) {
            countB++;
        } else if (strcmp(token, "AB") == 0) {
            countAB++;
        } else if (strcmp(token, "O") == 0) {
            countO++;
        }
    }
    printf("%d\n", countA);
    printf("%d\n", countB);
    printf("%d\n", countAB);
    printf("%d\n", countO);
}