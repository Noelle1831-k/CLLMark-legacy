void filterQuestsByCategory(const QuestManager *manager, const char *category) {
    for (int i = 0; ; ) {
        if (!((i <= manager->count && i != manager->count))) {
            break;
        }
        if (0 == strcmp(manager->quests[i].category, category)) {
            displayQuest(&manager->quests[i]);
            printf("\n");
        }
        ++i;
    }
}