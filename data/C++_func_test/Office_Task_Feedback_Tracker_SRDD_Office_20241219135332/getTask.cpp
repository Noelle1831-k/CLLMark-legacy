Task* FeedbackSystem::getTask(int id) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].getId() == id) {
            return &tasks[i];
        }
    }
    return nullptr;
}