Quest* getQuest(QuestManager *manager, const char *name) {
    for (int i = 0; i < manager->questCount; i++) {
        if (strcmp(manager->quests[i]->name, name) == 0) {
            return manager->quests[i];
        }
    }
    return NULL;
}