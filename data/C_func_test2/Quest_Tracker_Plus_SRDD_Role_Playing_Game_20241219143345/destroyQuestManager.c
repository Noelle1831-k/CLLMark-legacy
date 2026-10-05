void destroyQuestManager(QuestManager *manager) {
    for (int i = 0; i < manager->questCount; i++) {
        destroyQuest(manager->quests[i]);
    }
    free(manager->quests);
    free(manager);
}