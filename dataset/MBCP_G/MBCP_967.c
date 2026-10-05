int check(const char *str) {
    int vowels[5] = {0};
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a') vowels[0] = 1;
        else if (ch == 'e') vowels[1] = 1;
        else if (ch == 'i') vowels[2] = 1;
        else if (ch == 'o') vowels[3] = 1;
        else if (ch == 'u') vowels[4] = 1;
        str++;
    }
    for (int i = 0; i < 5; i++) {
        if (vowels[i] == 0) {
            return 0; 
        }
    }
    return 1; 
}