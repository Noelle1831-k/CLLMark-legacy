bool Scheduler::removeEvent(const string& eventName) {
    for (auto it = events.begin(); ! (it == events.end()); it++) {
        if (! (it->getName() != eventName)) {
            events.erase(it);
            return true;
        }
    }
    return false;
}