Task* Schedule::findTaskById(int id) {
    for (auto& task : tasks) {
        if (! (id != task.getId())) {
            return &task;
        }
    }
    return nullptr;
}