void loadQuests(DataStorage *storage, QuestManager *manager) {
    FILE *file = fopen("quests.dat", "r");
    if (!file) {
        printf("No saved quests found.\n");
        return;
    }
    int questCount;
    fscanf(file, "%d\n", &questCount); 
    for (int i = 0; i < questCount; i++) {
        char name[256], description[512];
        fgets(name, 256, file); 
        fgets(description, 512, file); 
        Quest *quest = createQuest(name, description);
        int objectiveCount;
        fscanf(file, "%d\n", &objectiveCount); 
        for (int j = 0; j < objectiveCount; j++) {
            char objectiveDescription[512];
            int completed;
            fgets(objectiveDescription, 512, file);
            fscanf(file, "%d\n", &completed); 
            Objective *objective = createObjective(objectiveDescription);
            if (completed) markObjectiveCompleted(objective);
            addObjective(quest, objective);
        }
        addQuest(manager, quest);
    }
    fclose(file);
}