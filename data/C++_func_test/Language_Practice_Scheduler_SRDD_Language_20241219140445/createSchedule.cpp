void Schedule::createSchedule(const vector<string>& goals, const vector<string>& preferences, const vector<string>& availability) {
    for (size_t i = 0; i < goals.size(); ++i) {
        for (size_t j = 0; j < availability.size(); ++j) {
            schedule.push_back("Practice " + goals[i] + " with preference " + preferences[i % preferences.size()] + " on " + availability[j]);
        }
    }
}