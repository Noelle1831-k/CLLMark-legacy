int main() {
    char letters[MAX_LETTERS];
    char **valid_words;
    int word_count, i;
    printf("Welcome to the Word Finder Application!\n");
    printf("Enter the letters you have (max %d): ", MAX_LETTERS - 1);
    scanf("%s", letters);
    if (!load_dictionary("dictionary.txt")) {
        printf("Error: Unable to load dictionary.\n");
        return 1;
    }
    valid_words = find_words(letters, &word_count);
    if (word_count > 0) {
        printf("\nValid words:\n");
        for (i = 0; i < word_count; i++) {
            printf("%s\n", valid_words[i]);
            free(valid_words[i]); 
        }
        free(valid_words); 
    } else {
        printf("\nNo valid words found.\n");
    }
    unload_dictionary();
    return 0;
}