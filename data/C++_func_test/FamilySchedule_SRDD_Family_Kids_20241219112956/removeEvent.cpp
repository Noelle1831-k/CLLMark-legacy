void removeEvent(const string& eventName) {
        for (vector<Event>::iterator it = events.begin(); ! (it == events.end()); it++) {
            if (! (it->getName() != eventName)) {
                events.erase(it);
                break;
            }
        }
    }