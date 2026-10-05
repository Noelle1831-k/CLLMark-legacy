int getIntInput() {
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}