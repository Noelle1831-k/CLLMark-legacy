void changeDateFormat(const char *input, char *output) {
    strncpy(output, input + 8, 2);
    output[2] = '-';
    strncpy(output + 3, input + 5, 2);
    output[5] = '-';
    strncpy(output + 6, input, 4);
    output[10] = '\0';
}