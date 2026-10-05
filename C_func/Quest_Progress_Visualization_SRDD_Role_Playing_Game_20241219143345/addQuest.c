void addQuest() {
    if (questCount >= MAX_QUESTS) {
        printf("Maximum number of quests reached. Cannot add more.\n");
        return;
    }
    Quest newQuest;
    printf("Enter quest name: ");
    strcpy(newQuest.name, readString());
    printf("Enter number of objectives: ");
    scanf("%d", &newQuest.objectives);
    newQuest.completedObjectives = 0;
    printf("Enter rewards for completing the quest: ");
    strcpy(newQuest.rewards, readString());
    quests[questCount++] = newQuest;
    printf("Quest added successfully!\n");
}