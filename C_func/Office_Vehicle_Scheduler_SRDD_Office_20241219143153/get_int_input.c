int get_int_input() {
    char buffer[20];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}