void fgetsSafe(char *str, int size) {
    if (fgets(str, size, stdin)) {
        str[strcspn(str, "\n")] = '\0'; 
    }
}