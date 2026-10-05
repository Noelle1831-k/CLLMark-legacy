void TaskManager::listTasks() {
    cout << "\nTasks:\n";
    for (std::vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        it->displayDetails();
    }
}