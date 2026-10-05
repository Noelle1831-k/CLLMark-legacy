int minFlipToMakeStringAlternate(const char* str) {
    int flip1 = 0, flip2 = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char expectedChar = (i % 2 == 0) ? '0' : '1';
        if (str[i] != expectedChar) {
            flip1++;
        }
        expectedChar = (i % 2 == 0) ? '1' : '0';
        if (str[i] != expectedChar) {
            flip2++;
        }
    }
    return flip1 < flip2 ? flip1 : flip2;
}