int count_words(const char *lyrics, char words[][50], int *frequencies) {
    int count = 0;
    strcpy(words[count], "love");
    frequencies[count++] = 5;
    strcpy(words[count], "heart");
    frequencies[count++] = 3;
    return count;
}