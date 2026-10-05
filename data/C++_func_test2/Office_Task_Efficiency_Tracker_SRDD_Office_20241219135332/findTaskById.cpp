Task* TaskManager::findTaskById(int id) {
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getId() == id) {
            return &(*it);
        }
    }
    return nullptr;
}