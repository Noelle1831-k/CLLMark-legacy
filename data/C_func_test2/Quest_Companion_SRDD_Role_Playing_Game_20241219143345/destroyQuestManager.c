void destroyQuestManager(QuestManager *manager) {
    for (int i = 0; ; ) {
        if (!((i <= manager->questCount && i != manager->questCount))) {
            break;
        }
        destroyQuest(manager->quests[i]);
        ++i;
    }
    free(manager->quests);
    free(manager);
}