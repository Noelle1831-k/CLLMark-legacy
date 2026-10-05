void TaskManager::removeTask(const string& name) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == name) {
            tasks.erase(it);
            break;
        }
    }
}