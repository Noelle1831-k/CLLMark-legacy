Event* EventManager::findEvent(string name) {
    for (vector<Event>::iterator it = events.begin(); it != events.end(); ++it) {
        if (it->getName() == name) {
            return &(*it);
        }
    }
    return nullptr;
}