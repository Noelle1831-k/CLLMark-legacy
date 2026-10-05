void Schedule::displayTasks() const {
    for (const auto& task : tasks) {
        task.printTask();
    }
}