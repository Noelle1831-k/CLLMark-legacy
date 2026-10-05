void Scheduler::displayAllEvents() const {
    if (events.empty()) {
        cout << "No events in the schedule." << endl;
    } else {
        for (const auto& event : events) {
            event.displayEvent();
            cout << "-----------------------" << endl;
        }
    }
}