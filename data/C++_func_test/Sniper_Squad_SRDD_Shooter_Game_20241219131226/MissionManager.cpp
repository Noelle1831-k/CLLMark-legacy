MissionManager::MissionManager() {
    missions.push_back(make_shared<Mission>("Desert"));
    missions.push_back(make_shared<Mission>("Forest"));
}