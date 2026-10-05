void Scheduler::scheduleScans() {
    cout << "Scheduling scans..." << endl;
    addTask("Daily scan at 2 AM");
    addTask("Weekly full scan on Sundays");
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << "Scheduled: " << scheduledTasks[i] << endl;
    }
}