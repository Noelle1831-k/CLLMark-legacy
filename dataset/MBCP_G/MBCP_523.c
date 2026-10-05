#define MIN_LENGTH 8
void checkString(const char *str, char result[][50], int *result_count) {
    bool has_upper = false, has_lower = false, has_digit = false;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (isupper((unsigned char)str[i])) has_upper = true;
        if (islower((unsigned char)str[i])) has_lower = true;
        if (isdigit((unsigned char)str[i])) has_digit = true;
    }
    *result_count = 0;
    if (!has_upper)
        strcpy(result[(*result_count)++], "String must have 1 upper case character.");
    if (!has_digit)
        strcpy(result[(*result_count)++], "String must have 1 number.");
    if (len < MIN_LENGTH)
        strcpy(result[(*result_count)++], "String length should be atleast 8.");
    if (*result_count == 0) 
        strcpy(result[(*result_count)++], "Valid string.");
}