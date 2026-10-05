void Schedule::updateTaskStatus(const std::string& taskName, bool isCompleted) {
    for (std::vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == taskName) {
            it->setStatus(isCompleted);
            break;
        }
    }
}