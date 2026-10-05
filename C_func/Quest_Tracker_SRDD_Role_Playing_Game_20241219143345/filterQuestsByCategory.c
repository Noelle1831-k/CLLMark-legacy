void filterQuestsByCategory(const QuestManager *manager, const char *category) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->quests[i].category, category) == 0) {
            displayQuest(&manager->quests[i]);
            printf("\n");
        }
    }
}