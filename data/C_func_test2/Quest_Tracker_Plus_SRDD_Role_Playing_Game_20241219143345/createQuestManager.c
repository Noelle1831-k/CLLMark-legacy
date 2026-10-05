QuestManager *createQuestManager() {
    QuestManager *manager = (QuestManager *)malloc(sizeof(QuestManager));
    manager->quests = (Quest **)malloc(sizeof(Quest *) * INITIAL_CAPACITY);
    manager->questCount = 0;
    manager->capacity = INITIAL_CAPACITY;
    return manager;
}