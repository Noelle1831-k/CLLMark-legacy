void ReportGenerator::generateReport(const Schedule& schedule) {
    int completedTasks = 0;
    int totalTasks = schedule.getTasks().size();
    for (std::vector<Task>::const_iterator it = schedule.getTasks().begin(); it != schedule.getTasks().end(); ++it) {
        if (it->getStatus()) {
            completedTasks++;
        }
    }
    std::cout << "Productivity Report: " << std::endl;
    std::cout << "Total Tasks: " << totalTasks << std::endl;
    std::cout << "Completed Tasks: " << completedTasks << std::endl;
    std::cout << "Completion Rate: " << (static_cast<double>(completedTasks) / totalTasks) * 100 << "%" << std::endl;
}