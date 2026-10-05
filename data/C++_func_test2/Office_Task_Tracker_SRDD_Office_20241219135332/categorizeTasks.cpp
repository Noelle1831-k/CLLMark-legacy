void TaskManager::categorizeTasks() {
    cout << "Tasks categorized by category:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "Category: " << tasks[i].getCategory() << "\n";
        tasks[i].displayTask();
    }
}