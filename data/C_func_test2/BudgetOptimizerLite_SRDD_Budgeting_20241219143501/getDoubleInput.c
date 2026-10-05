double getDoubleInput() {
    char *buffer = (char*)malloc(sizeof(char) * 50);
    fgets(buffer, sizeof(buffer), stdin);
    return atof(buffer);
}