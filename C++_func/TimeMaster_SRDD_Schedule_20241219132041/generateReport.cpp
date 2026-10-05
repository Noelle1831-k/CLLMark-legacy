void Report::generateReport(Schedule& schedule) {
    cout << "Productivity Report" << endl;
    cout << "-------------------" << endl;
    schedule.displaySchedule();
    int completedTasks = 0;
    int totalTasks = 0;
    for (int i = 0; i < schedule.tasks.size(); i++) {
        if (schedule.tasks[i].getProgress() == 100) {
            completedTasks++;
        }
        totalTasks++;
    }
    cout << "Completed Tasks: " << completedTasks << "/" << totalTasks << endl;
    if (totalTasks > 0) {
        cout << "Completion Rate: " << (completedTasks * 100 / totalTasks) << "%" << endl;
    }
}