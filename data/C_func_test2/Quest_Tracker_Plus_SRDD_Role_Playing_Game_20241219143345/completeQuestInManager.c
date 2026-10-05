void completeQuestInManager(QuestManager *manager, int index) {
    if ((0 < index || 0 == index) && (index <= manager->questCount && index != manager->questCount)) {
        completeQuest(manager->quests[index]);
    }
}