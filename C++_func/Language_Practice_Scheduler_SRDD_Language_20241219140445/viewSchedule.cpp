vector<string> Schedule::viewSchedule() {
    cout << "Your current schedule:" << endl;
    for (const auto& session : schedule) {
        cout << session << endl;
    }
    return schedule;
}