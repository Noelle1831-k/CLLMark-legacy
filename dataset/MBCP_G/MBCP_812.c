void roadRd(char *street) {
    char *pos = strstr(street, " Road");
    if (pos) {
        strcpy(pos, " Rd.");
    }
}