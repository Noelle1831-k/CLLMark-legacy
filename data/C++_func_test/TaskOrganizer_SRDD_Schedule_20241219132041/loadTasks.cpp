vector<Task> FileHandler::loadTasks() {
    ifstream file("tasks.txt");
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return {};
    }
    vector<Task> tasks;
    string name, timeSlot;
    int priority;
    bool completed;
    while (file >> name >> priority >> timeSlot >> completed) {
        Task task(name, priority, timeSlot);
        if (completed) task.markComplete();
        tasks.push_back(task);
    }
    file.close();
    return tasks;
}