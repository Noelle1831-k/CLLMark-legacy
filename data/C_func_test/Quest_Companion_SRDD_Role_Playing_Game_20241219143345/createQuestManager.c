QuestManager* createQuestManager() {
    QuestManager *manager = (QuestManager*)malloc(sizeof(QuestManager));
    manager->quests = NULL;
    manager->questCount = 0;
    return manager;
}