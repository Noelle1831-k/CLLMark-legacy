void displayQuestList() {
    if (questCount == 0) {
        printf("No quests available.\n");
        return;
    }
    for (int i = 0; i < questCount; i++) {
        Quest quest = quests[i];
        printf("Quest %d: %s [%d/%d objectives completed]\n", i + 1, quest.name, quest.completedObjectives, quest.objectives);
    }
}