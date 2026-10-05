void MissionManager::assignMission(const vector<shared_ptr<Player>>& players) {
    for (size_t i = 0; i < missions.size(); i++) {
        if (!missions[i]->isCompleted()) {
            cout << "Assigning mission in " << missions[i]->getLocation() << endl;
            missions[i]->completeMission();
            break;
        }
    }
}