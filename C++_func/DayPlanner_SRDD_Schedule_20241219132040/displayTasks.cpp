void DayPlanner::displayTasks() const {
    for (const auto& task : tasks) {
        task.display();
    }
}