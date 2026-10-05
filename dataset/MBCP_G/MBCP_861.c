int is_anagram(const char *str, const char *word) {
    int count[256] = {0};
    for(int i = 0; str[i] && word[i]; i++) {
        count[(unsigned char)str[i]]++;
        count[(unsigned char)word[i]]--;
    }
    if (strlen(str) != strlen(word)) return 0;
    for(int i = 0; i < 256; i++) {
        if(count[i]) return 0;
    }
    return 1;
}
void anagram_array(char *texts[], int size, const char *str, char *result[], int *result_size) {
    *result_size = 0;
    for(int i = 0; i < size; i++) {
        if(is_anagram(texts[i], str)) {
            result[*result_size] = texts[i];
            (*result_size)++;
        }
    }
}
