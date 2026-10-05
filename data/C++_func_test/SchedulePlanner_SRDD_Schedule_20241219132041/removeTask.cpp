void Schedule::removeTask(const std::string& taskName) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [&](Task& task) {
        return task.getName() == taskName;
    }), tasks.end());
}