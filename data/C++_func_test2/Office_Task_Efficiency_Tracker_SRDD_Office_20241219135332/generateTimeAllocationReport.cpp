void ReportGenerator::generateTimeAllocationReport(const TaskManager& taskManager) const {
    cout << "Time Allocation Report:" << endl;
    taskManager.displayAllTasks();
}