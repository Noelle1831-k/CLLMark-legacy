void displayQuestDetails() {
    if (questCount == 0) {
        printf("No quests available to display.\n");
        return;
    }
    printf("Enter the index of the quest to view details (1 to %d): ", questCount);
    int index = validateInputRange(1, questCount) - 1;
    Quest quest = quests[index];
    printf("Quest Name: %s\n", quest.name);
    printf("Progress: %d/%d objectives completed\n", quest.completedObjectives, quest.objectives);
    printf("Rewards: %s\n", quest.rewards);
    drawProgressBar(quest.completedObjectives, quest.objectives);
}