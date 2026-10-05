void addCustomPhrase() {
    char phrase[256];
    char category[50];
    char contextExample[256];
    printf("Enter your custom phrase: ");
    scanf(" %[^\n]", phrase);
    printf("Enter category for the phrase: ");
    scanf("%s", category);
    printf("Enter a context example for the phrase: ");
    scanf(" %[^\n]", contextExample);
    strcpy(phrasebook[phraseCount].phrase, phrase);
    strcpy(phrasebook[phraseCount].category, category);
    strcpy(phrasebook[phraseCount].contextExample, contextExample);
    phraseCount++;
    printf("Custom phrase added successfully.\n");
}