void TaskManager::updateTask(const string& name, int newPriority) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == name) {
            it->setPriority(newPriority);
            break;
        }
    }
}