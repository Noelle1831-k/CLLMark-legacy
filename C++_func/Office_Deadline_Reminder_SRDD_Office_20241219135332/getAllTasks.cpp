void TaskManager::getAllTasks() {
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        cout << it->getTaskDetails() << endl;
    }
}