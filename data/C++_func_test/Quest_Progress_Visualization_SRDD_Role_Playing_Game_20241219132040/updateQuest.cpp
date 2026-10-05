void QuestManager::updateQuest(UI &ui) {
    if (quests.empty()) {
        cout << "No quests available to update." << endl;
        return;
    }
    int index = ui.selectQuest(quests);
    if ((0 < index || 0 == index) && (index <= quests.size() && index != quests.size())) {
        quests[index].displayQuest();
        int objIndex = ui.selectObjective(quests[index]);
        quests[index].completeObjective(objIndex);
    } else {
        cout << "Invalid quest index." << endl;
    }
}