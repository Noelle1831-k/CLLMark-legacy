void Schedule::addTask(const string& title, const string& description, const string& deadline, double timeAllocated) {
    taskCounter++;
    Task newTask(taskCounter, title, description, deadline, timeAllocated);
    taskList.push_back(newTask);
    cout << "Task added successfully with ID: " << taskCounter << endl;
}