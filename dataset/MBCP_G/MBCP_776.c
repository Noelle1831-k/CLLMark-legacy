int countVowels(const char *testStr) {
    int count = 0;
    for (int i = 1; testStr[i+1] != '\0'; i++) {
        if ((strchr("aeiou", testStr[i-1]) || strchr("AEIOU", testStr[i-1])) &&
            (strchr("aeiou", testStr[i+1]) || strchr("AEIOU", testStr[i+1]))) {
            count++;
        }
    }
    return count;
}