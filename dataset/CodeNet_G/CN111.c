#define MAX_INPUT_LENGTH 200
typedef struct {
    char *compressed;
    char *binary;
    char *decompressed;
} Mapping;
Mapping firstTable[] = {
    {"?D", "111"},
    {"-C", "110"},
    {"'K", "101"},
    {"O", "100"},
    {"P", "011"},
    {"U", "010"},
    {"A", "001"},
    {NULL, NULL}
};
Mapping secondTable[] = {
    {"A", "001"},
    {"B", "010"},
    {"C", "011"},
    {"D", "100"},
    {"E", "101"},
    {"F", "110"},
    {"G", "111"},
    {"H", "01100"},
    {"I", "01101"},
    {"J", "01110"},
    {"K", "01111"},
    {"L", "10000"},
    {"M", "10001"},
    {"N", "10010"},
    {"O", "10011"},
    {"P", "10100"},
    {"Q", "10101"},
    {"R", "10110"},
    {"S", "10111"},
    {"T", "11000"},
    {"U", "11001"},
    {"V", "11010"},
    {"W", "11011"},
    {"X", "11100"},
    {"Y", "11101"},
    {"Z", "11110"},
    {NULL, NULL}
};
void replaceWithBinary(char* input, char* result) {
    char *ptr = input;
    while (*ptr) {
        int found = 0;
        for (int i = 0; firstTable[i].compressed != NULL; i++) {
            int len = strlen(firstTable[i].compressed);
            if (strncmp(ptr, firstTable[i].compressed, len) == 0) {
                strcat(result, firstTable[i].binary);
                ptr += len;
                found = 1;
                break;
            }
        }
        if (!found) {
            ptr++;
        }
    }
}
void replaceWithDecompressed(char* binary, char* result) {
    while (*binary) {
        int found = 0;
        for (int len = 5; len >= 3 && !found; len--) {
            for (int i = 0; secondTable[i].decompressed != NULL; i++) {
                if (strncmp(binary, secondTable[i].binary, len) == 0) {
                    strcat(result, secondTable[i].decompressed);
                    binary += len;
                    found = 1;
                    break;
                }
            }
        }
        if (!found) binary++;
    }
}
void decode(char* input, char* output) {
    char binaryResult[MAX_INPUT_LENGTH * 5] = "";
    replaceWithBinary(input, binaryResult);
    replaceWithDecompressed(binaryResult, output);
}
