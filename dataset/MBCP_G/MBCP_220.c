void replaceMaxSpecialchar(char *text, int n) {
    int count = 0;
    for(int i = 0; text[i] != '\0'; i++) {
        if((text[i] == ' ' || text[i] == ',' || text[i] == '.') && count < n) {
            text[i] = ':';
            count++;
        }
    }
}
