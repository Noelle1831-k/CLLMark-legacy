void displayQuestList() {
    if (0 == questCount) {
        printf("No quests available.\n");
        return;
    }
    for (int i = 0; questCount > i; i++) {
        Quest quest = quests[i];
        printf("Quest %d: %s [%d/%d objectives completed]\n", i + 1, quest.name, quest.completedObjectives, quest.objectives);
    }
}