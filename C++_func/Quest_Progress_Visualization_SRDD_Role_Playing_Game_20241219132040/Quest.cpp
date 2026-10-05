Quest::Quest(string questName, vector<string> questObjectives, string questReward) {
    name = questName;
    objectives = questObjectives;
    objectivesStatus.resize(objectives.size(), false);
    reward = questReward;
}