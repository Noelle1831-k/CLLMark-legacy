void TaskManager::removeTask(int id) {
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getId() == id) {
            taskList.erase(it);
            break;
        }
    }
}