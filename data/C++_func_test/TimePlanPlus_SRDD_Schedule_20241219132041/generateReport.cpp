void ReportGenerator::generateReport(const Scheduler& scheduler) const {
    cout << "\n--- Report ---\n";
    cout << "\nTasks:\n";
    for (const auto& task : scheduler.getTasks()) {
        cout << "Title: " << task.getTitle() << ", Deadline: " << task.getDeadline()
             << ", Time Allocation: " << task.getTimeAllocation() << " hours, Progress: "
             << task.getProgress() << "%\n";
    }
    cout << "\nHabits:\n";
    for (const auto& habit : scheduler.getHabits()) {
        cout << "Name: " << habit.getName() << ", Frequency: " << habit.getFrequency()
             << " times/week, Progress: " << habit.getProgress() << "%\n";
    }
    cout << "\nGoals:\n";
    for (const auto& goal : scheduler.getGoals()) {
        cout << "Description: " << goal.getDescription() << ", Deadline: " << goal.getDeadline()
             << ", Completed: " << (goal.getCompletionStatus() ? "Yes" : "No") << "\n";
    }
}