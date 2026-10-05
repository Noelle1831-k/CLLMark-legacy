void filterQuestsByTags(const QuestManager *manager, const char *tags) {
    for (int i = 0; i < manager->count; i++) {
        if (strstr(manager->quests[i].tags, tags) != NULL) {
            displayQuest(&manager->quests[i]);
            printf("\n");
        }
    }
}