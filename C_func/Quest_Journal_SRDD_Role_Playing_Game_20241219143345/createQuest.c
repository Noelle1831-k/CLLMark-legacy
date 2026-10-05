void createQuest() {
    if (questCount < 100) {
        printf("Enter quest name: ");
        getchar();  
        fgets(quests[questCount].name, sizeof(quests[questCount].name), stdin);
        quests[questCount].name[strcspn(quests[questCount].name, "\n")] = 0; 
        printf("Enter quest details: ");
        fgets(quests[questCount].details, sizeof(quests[questCount].details), stdin);
        quests[questCount].details[strcspn(quests[questCount].details, "\n")] = 0; 
        printf("Enter quest objectives: ");
        fgets(quests[questCount].objectives, sizeof(quests[questCount].objectives), stdin);
        quests[questCount].objectives[strcspn(quests[questCount].objectives, "\n")] = 0; 
        quests[questCount].progress = 0;
        questCount++;
    } else {
        printf("Quest limit reached.\n");
    }
}