Task* Schedule::findTaskByName(const std::string& taskName) {
    for (std::vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (! (it->getName() != taskName)) {
            return &(*it);
        }
    }
    return nullptr;
}