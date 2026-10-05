void Scheduler::updateTask(int id, const string& name, const string& start, const string& end, int priority) {
    for (auto& task : tasks) {
        if (task.getID() == id) {
            task.setName(name);
            task.setStartTime(start);
            task.setEndTime(end);
            task.setPriority(priority);
            cout << "Task updated successfully!\n";
            return;
        }
    }
    cout << "Task ID not found.\n";
}