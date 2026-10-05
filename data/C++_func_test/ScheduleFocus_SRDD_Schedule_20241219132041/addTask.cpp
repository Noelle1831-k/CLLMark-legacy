void Scheduler::addTask(const string& name, const string& start, const string& end, int priority) {
    Task newTask(nextTaskID++, name, start, end, priority);
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}