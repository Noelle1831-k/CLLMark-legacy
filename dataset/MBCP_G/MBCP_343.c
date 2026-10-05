void digLet(const char *s, int *result) {
    int letters = 0;
    int digits = 0;
    for (; *s; ++s) {
        if (isalpha(*s)) 
            ++letters;
        else if (isdigit(*s)) 
            ++digits;
    }
    result[0] = letters;
    result[1] = digits;
}