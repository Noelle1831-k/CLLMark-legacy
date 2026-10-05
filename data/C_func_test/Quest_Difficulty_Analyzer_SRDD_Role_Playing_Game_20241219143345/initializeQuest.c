void initializeQuest(Quest *quest) {
    printf("Enter enemy strength (1-10): ");
    quest->enemyStrength = getIntegerInput(1, 10);
    printf("Enter required skills (1-10): ");
    quest->requiredSkills = getIntegerInput(1, 10);
    printf("Enter time constraints (1-10): ");
    quest->timeConstraints = getIntegerInput(1, 10);
}