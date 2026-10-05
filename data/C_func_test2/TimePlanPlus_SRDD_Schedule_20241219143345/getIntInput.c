int getIntInput() {
    char buffer[16];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}