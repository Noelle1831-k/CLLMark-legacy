void extract_words(char *input) {
    char *start = input;
    char *end = input;
    char output[1024] = "";
    int length;
    while (*end) {
        if (isspace(*end) || *end == '.' || *end == ',') {
            length = end - start;
            if (length >= 3 && length <= 6) {
                strncat(output, start, length);
                strcat(output, " ");
            }
            end++;
            while (isspace(*end) || *end == '.' || *end == ',') 
                end++;
            start = end;
        } else {
            end++;
        }
    }
    length = end - start;
    if (length >= 3 && length <= 6) {
        strncat(output, start, length);
    }
    printf("%s\n", output);
}
