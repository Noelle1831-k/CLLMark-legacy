void QuestManager::addQuest(UI &ui) {
    string name;
    vector<string> objectives;
    string reward;
    ui.getQuestDetails(name, objectives, reward);
    Quest newQuest(name, objectives, reward);
    quests.push_back(newQuest);
}