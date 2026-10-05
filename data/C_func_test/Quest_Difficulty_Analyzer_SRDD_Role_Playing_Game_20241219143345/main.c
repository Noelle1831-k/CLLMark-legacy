int main(void) {
    printf("Welcome to the Quest Difficulty Analyzer!\n");
    Quest quest;
    initializeQuest(&quest);
    displayQuest(&quest);
    int difficulty = calculateDifficulty(&quest);
    printf("The difficulty rating for this quest is: %d\n", difficulty);
    return 0;
}