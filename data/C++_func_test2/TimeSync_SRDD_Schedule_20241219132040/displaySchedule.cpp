void Scheduler::displaySchedule() {
    cout << "Current Schedule:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i << ": ";
        tasks[i].displayTask();
    }
}