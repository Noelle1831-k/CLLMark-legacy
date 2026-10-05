void countAlphaDigSpl(const char* str, int* countAlpha, int* countDigit, int* countSpecial) {
    *countAlpha = *countDigit = *countSpecial = 0;
    while (*str) {
        if (isalpha(*str)) {
            (*countAlpha)++;
        } else if (isdigit(*str)) {
            (*countDigit)++;
        } else {
            (*countSpecial)++;
        }
        str++;
    }
}