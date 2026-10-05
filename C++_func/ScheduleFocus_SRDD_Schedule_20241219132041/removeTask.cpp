void Scheduler::removeTask(int id) {
    auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getID() == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task removed successfully!\n";
    } else {
        cout << "Task ID not found.\n";
    }
}