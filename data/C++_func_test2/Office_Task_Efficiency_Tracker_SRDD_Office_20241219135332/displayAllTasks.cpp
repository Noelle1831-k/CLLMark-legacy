void TaskManager::displayAllTasks() const {
    for (vector<Task>::const_iterator it = taskList.begin(); it != taskList.end(); ++it) {
        it->displayTaskDetails();
    }
}