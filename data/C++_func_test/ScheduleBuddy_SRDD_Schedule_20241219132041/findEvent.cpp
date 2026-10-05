Event* Scheduler::findEvent(const string& eventName) {
    for (auto& event : events) {
        if (event.getName() == eventName) {
            return &event;
        }
    }
    return nullptr;
}