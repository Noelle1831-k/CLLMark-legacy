vector<string> Schedule::viewSchedule() {
    printf("Your current schedule:\n");
    for (const auto& session : schedule) {
        cout << session << endl;
    }
    return schedule;
}