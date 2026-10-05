string QuestGuide::getHint(string questName) const {
    if (hints.find(questName) != hints.end()) {
        return hints.at(questName);
    }
    return "No hints available for this quest.";
}