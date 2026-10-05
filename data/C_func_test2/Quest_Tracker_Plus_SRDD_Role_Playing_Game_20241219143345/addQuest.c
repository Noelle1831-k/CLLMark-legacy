void addQuest(QuestManager *manager, Quest *quest) {
    if (manager->questCount >= manager->capacity) {
        manager->capacity *= 2;
        manager->quests = (Quest **)realloc(manager->quests, sizeof(Quest *) * manager->capacity);
    }
    manager->quests[manager->questCount++] = quest;
}