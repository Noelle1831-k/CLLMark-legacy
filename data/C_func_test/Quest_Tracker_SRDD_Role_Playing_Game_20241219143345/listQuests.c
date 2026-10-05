void listQuests(const QuestManager *manager) {
    for (int i = 0; manager->count > i; i++) {
        displayQuest(&manager->quests[i]);
        printf("\n");
    }
}