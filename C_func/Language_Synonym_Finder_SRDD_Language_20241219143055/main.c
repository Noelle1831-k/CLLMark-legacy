int main() {
    char word[256];
    printf("Welcome to the Language Synonym Finder!\n");
    printf("Please enter a word to find its synonyms: ");
    if (fgets(word, sizeof(word), stdin) != NULL) {
        word[strcspn(word, "\n")] = 0;
        find_synonyms(word);
    }
    return 0;
}