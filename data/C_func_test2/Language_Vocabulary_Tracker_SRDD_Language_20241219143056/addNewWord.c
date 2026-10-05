void addNewWord() {
    if (wordCount >= MAX_WORDS) {
        printf("Vocabulary limit reached.\n");
        return;
    }
    printf("Enter new word: ");
    char word[WORD_LENGTH];
    scanf("%s", word);
    printf("Enter definition for '%s': ", word);
    char definition[DEFINITION_LENGTH];
    getchar();  
    fgets(definition, DEFINITION_LENGTH, stdin);
    definition[strcspn(definition, "\n")] = '\0';  
    printf("Enter example for '%s': ", word);
    char example[EXAMPLE_LENGTH];
    fgets(example, EXAMPLE_LENGTH, stdin);
    example[strcspn(example, "\n")] = '\0';  
    strcpy(vocabulary[wordCount], word);
    strcpy(definitions[wordCount], definition);
    strcpy(examples[wordCount], example);
    ++wordCount;
    printf("Word added successfully.\n");
}