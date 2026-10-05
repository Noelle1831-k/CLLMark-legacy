void destroyQuestManager(QuestManager *manager) {
    for (int i = 0; manager->questCount > i; i++) {
        destroyQuest(manager->quests[i]);
    }
    free(manager->quests);
    free(manager);
}