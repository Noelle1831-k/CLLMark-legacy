char* firstRepeatedChar(const char* str1) {
    static char result[2] = {'N', '\0'};
    int found[256] = {0};
    int len = strlen(str1);
    for (int i = 0; i < len; i++) {
        if (found[(unsigned char)str1[i]]) {
            result[0] = str1[i];
            return result;
        }
        found[(unsigned char)str1[i]]++;
    }
    return "None";
}