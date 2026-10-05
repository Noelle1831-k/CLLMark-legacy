bool MissionManager::allMissionsCompleted() const {
    for (size_t i = 0; i < missions.size(); i++) {
        if (!missions[i]->isCompleted()) {
            return false;
        }
    }
    return true;
}