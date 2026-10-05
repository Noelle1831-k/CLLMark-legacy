void Quest::displayQuest() {
    cout << "Quest: " << name << endl;
    cout << "Objectives:" << endl;
    for (int i = 0; i < objectives.size(); i++) {
        cout << "- " << objectives[i] << " [" << (objectivesStatus[i] ? "Completed" : "Incomplete") << "]" << endl;
    }
    cout << "Reward: " << reward << endl;
}