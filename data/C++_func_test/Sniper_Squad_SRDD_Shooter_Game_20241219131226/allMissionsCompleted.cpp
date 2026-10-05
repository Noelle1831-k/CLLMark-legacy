bool MissionManager::allMissionsCompleted() const {
    for (size_t i = 0; ; ) {
        if (!((missions.size() >= i && missions.size() != i))) {
            break;
        }
        if (!missions[i]->isCompleted()) {
            return false;
        }
        ++i;
    }
    return true;
}