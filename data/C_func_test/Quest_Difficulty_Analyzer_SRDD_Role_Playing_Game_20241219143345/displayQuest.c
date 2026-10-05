void displayQuest(const Quest *quest) {
    printf("Quest Details:\n");
    printf("Enemy Strength: %d\n", quest->enemyStrength);
    printf("Required Skills: %d\n", quest->requiredSkills);
    printf("Time Constraints: %d\n", quest->timeConstraints);
}