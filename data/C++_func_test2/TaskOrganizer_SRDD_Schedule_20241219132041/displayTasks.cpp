void TaskManager::displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "           All Tasks              " << endl;
    cout << "----------------------------------" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "ID: " << i << endl;
        tasks[i].printTask();
    }
}