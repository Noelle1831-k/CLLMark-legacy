void Schedule::filterTasksByStatus(const string& status) const {
    for (const auto& task : tasks) {
        if (status == task.getStatus()) {
            task.printTask();
        }
    }
}