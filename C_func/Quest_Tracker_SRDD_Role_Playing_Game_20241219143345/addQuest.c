void addQuest(QuestManager *manager, Quest quest) {
    if (manager->count < 100) {
        manager->quests[manager->count++] = quest;
        printf("Quest added successfully!\n");
    } else {
        printf("Quest list is full!\n");
    }
}