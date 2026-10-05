void Schedule::filterTasksByStatus(const string& status) const {
    for (const auto& task : tasks) {
        if (task.getStatus() == status) {
            task.printTask();
        }
    }
}