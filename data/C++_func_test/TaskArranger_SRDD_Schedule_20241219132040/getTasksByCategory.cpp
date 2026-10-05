void TaskManager::getTasksByCategory(const string& category) const {
    bool found = false;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getCategory() == category) {
            tasks[i].displayTask();
            found = true;
        }
    }
    if (!found) {
        cout << "No tasks found in category: " << category << endl;
    }
}