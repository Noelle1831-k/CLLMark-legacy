void Scheduler::viewTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Start" << setw(10) << "End" << setw(10) << "Priority\n";
    for (const auto& task : tasks) {
        cout << left << setw(5) << task.getID() << setw(20) << task.getName() << setw(10) << task.getStartTime() << setw(10) << task.getEndTime() << setw(10) << task.getPriority() << "\n";
    }
}