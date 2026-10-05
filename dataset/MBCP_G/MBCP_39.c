#define MAX_LEN 1000
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
bool canRearrange(char *s) {
    int count[26] = {0};
    int max_count = 0;
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] > max_count) {
            max_count = count[s[i] - 'a'];
        }
    }
    return max_count <= (strlen(s) + 1) / 2;
}
void rearangeString(char *s, char *result) {
    if (!canRearrange(s)) {
        strcpy(result, "");
        return;
    }
    int count[26] = {0};
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
    }
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            if (index >= strlen(s)) index = 1;
            result[index] = 'a' + i;
            count[i]--;
            index += 2;
        }
    }
    result[strlen(s)] = '\0';
}