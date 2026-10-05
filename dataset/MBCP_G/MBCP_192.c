bool checkString(const char *str) {
    bool has_letter = false;
    bool has_number = false;
    while (*str) {
        if (isalpha(*str)) {
            has_letter = true;
        }
        if (isdigit(*str)) {
            has_number = true;
        }
        if (has_letter && has_number) {
            return true;
        }
        str++;
    }
    return false;
}