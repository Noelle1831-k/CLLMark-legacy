void QuestManager::removeQuest(UI &ui) {
    if (quests.empty()) {
        cout << "No quests available to remove." << endl;
        return;
    }
    int index = ui.selectQuest(quests);
    if (index >= 0 && index < quests.size()) {
        quests.erase(quests.begin() + index);
        cout << "Quest removed successfully." << endl;
    } else {
        cout << "Invalid quest index." << endl;
    }
}