void TaskManager::sortTasksByPriority() {
    quickSort(0, tasks.size() - 1);
    cout << "Tasks sorted by priority successfully!" << endl;
}