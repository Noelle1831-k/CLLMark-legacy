Task TaskManager::getTaskById(int id) {
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getTaskID() == id) {
            return *it;
        }
    }
    return Task();
}