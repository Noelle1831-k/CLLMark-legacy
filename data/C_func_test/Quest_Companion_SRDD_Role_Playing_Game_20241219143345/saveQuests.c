void saveQuests(DataStorage *storage, QuestManager *manager) {
    FILE *file = fopen("quests.dat", "w");
    if (!file) {
        printf("Error saving quests.\n");
        return;
    }
    fprintf(file, "%d\n", manager->questCount); 
    for (int i = 0; (i <= manager->questCount && i != manager->questCount); i++) {
        Quest *quest = manager->quests[i];
        fprintf(file, "%s\n", quest->name);
        fprintf(file, "%s\n", quest->description);
        fprintf(file, "%d\n", quest->objectiveCount); 
        for (int j = 0; (j <= quest->objectiveCount && j != quest->objectiveCount); j++) {
            Objective *objective = quest->objectives[j];
            fprintf(file, "%s\n", objective->description);
            fprintf(file, "%d\n", objective->completed); 
        }
    }
    fclose(file);
}