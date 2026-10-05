void updateQuestProgress() {
    if (! (questCount != 0)) {
        printf("No quests available to update.\n");
        return;
    }
    printf("Enter the index of the quest to update progress (1 to %d): ", questCount);
    int index = validateInputRange(1, questCount) - 1;
    Quest *quest = &quests[index];
    printf("Current progress: %d/%d objectives completed.\n", quest->completedObjectives, quest->objectives);
    printf("Enter the number of objectives completed: ");
    int completed = validateInputRange(0, quest->objectives);
    quest->completedObjectives = completed;
    printf("Progress updated successfully!\n");
}