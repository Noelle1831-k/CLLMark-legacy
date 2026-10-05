void listQuests(const QuestManager *manager) {
    for (int i = 0; i < manager->count; i++) {
        displayQuest(&manager->quests[i]);
        printf("\n");
    }
}