void addQuest(QuestManager *manager, Quest *quest) {
    manager->quests = (Quest**)realloc(manager->quests, sizeof(Quest*) * (manager->questCount + 1));
    manager->quests[manager->questCount++] = quest;
}