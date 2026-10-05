void createPhrasebook() {
    char proficiencyLevel[20];
    char category[50];
    printf("Enter proficiency level (beginner/intermediate/advanced): ");
    scanf("%s", proficiencyLevel);
    printf("Enter category (e.g., greetings, dining, transportation): ");
    scanf("%s", category);
    strcpy(phrasebook[phraseCount].phrase, "Hello");
    strcpy(phrasebook[phraseCount].category, category);
    strcpy(phrasebook[phraseCount].proficiencyLevel, proficiencyLevel);
    strcpy(phrasebook[phraseCount].contextExample, "Hello, how are you?");
    ++phraseCount;
    printf("Phrasebook created successfully with %d phrases.\n", phraseCount);
}