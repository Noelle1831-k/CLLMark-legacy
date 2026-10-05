bool isIsomorphic(const char* str1, const char* str2) {
    if (strlen(str1) != strlen(str2))
        return false;
    int map1[256] = {0};
    int map2[256] = {0};
    for (int i = 0; str1[i] != '\0'; i++) {
        char c1 = str1[i];
        char c2 = str2[i];
        if (map1[c1] == 0 && map2[c2] == 0) {
            map1[c1] = c2;
            map2[c2] = c1;
        } else if (map1[c1] != c2 || map2[c2] != c1) {
            return false;
        }
    }
    return true;
}