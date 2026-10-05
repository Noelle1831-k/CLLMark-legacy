void Report::generateReport(const Schedule& schedule) {
    cout << "Generating report..." << endl;
    totalTasks = schedule.getTasks().size();
    completedTasks = 0; 
    priorityDistribution = vector<int>(5, 0); 
    for (vector<Task>::const_iterator it = schedule.getTasks().begin(); it != schedule.getTasks().end(); ++it) {
        int priority = it->getTaskDetails().find("Priority: ") + 10;
        priorityDistribution[priority - 1]++;
    }
}