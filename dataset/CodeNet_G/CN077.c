void decompressString(const char* input, char* output) {
    const char* ptr = input;
    char* outPtr = output;
    while (*ptr != '\0') {
        if (*ptr == '@' && isdigit(*(ptr + 1))) {
            int count = *(ptr + 1) - '0';
            char repeatChar = *(ptr + 2);
            for (int i = 0; i < count; i++) {
                *outPtr++ = repeatChar;
            }
            ptr += 3;
        } else {
            *outPtr++ = *ptr++;
        }
    }
    *outPtr = '\0';
}