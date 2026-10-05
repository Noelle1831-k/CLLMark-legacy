int uniqueCharacters(const char *str) {
    int char_set[128] = {0}; 
    while (*str) {
        int val = (int)(*str);
        if (char_set[val]) {
            return 0; 
        }
        char_set[val] = 1;
        str++;
    }
    return 1; 
}