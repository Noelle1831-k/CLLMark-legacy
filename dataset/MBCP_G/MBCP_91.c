bool findSubstring(const char* strList[], int listSize, const char* subStr) {
    for (int i = 0; i < listSize; ++i) {
        if (strstr(strList[i], subStr) != NULL) {
            return true;
        }
    }
    return false;
}
