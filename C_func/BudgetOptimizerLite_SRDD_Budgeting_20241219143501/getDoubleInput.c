double getDoubleInput() {
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    return atof(buffer);
}