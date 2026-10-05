void markQuestComplete(QuestManager *manager, int id) {
    for (int i = 0; i < manager->count; i++) {
        if (manager->quests[i].id == id) {
            manager->quests[i].isComplete = 1;
            printf("Quest marked as complete!\n");
            return;
        }
    }
    printf("Quest not found!\n");
}