void TaskManager::searchTask(string query) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getTitle().find(query) != string::npos || tasks[i].getCategory().find(query) != string::npos) {
            tasks[i].displayTask();
        }
    }
}