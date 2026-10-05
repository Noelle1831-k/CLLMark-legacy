void Project::removeTask(int taskId) {
    for (vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getTaskId() == taskId) {
            tasks.erase(it);
            break;
        }
    }
}