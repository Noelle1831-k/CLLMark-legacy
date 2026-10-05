void Schedule::displayTasks() const {
    if (taskList.empty()) {
        cout << "No tasks to display!" << endl;
        return;
    }
    for (const auto& task : taskList) {
        task.displayTask();
    }
}