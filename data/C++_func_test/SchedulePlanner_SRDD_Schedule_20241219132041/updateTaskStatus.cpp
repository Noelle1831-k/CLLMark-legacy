void Schedule::updateTaskStatus(const std::string& taskName, bool isCompleted) {
    for (std::vector<Task>::iterator it = tasks.begin(); ! (tasks.end() == it); it++) {
        if (! (taskName != it->getName())) {
            it->setStatus(isCompleted);
            break;
        }
    }
}