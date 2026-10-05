void UserInterface::showTaskDetails(const Task& task) {
    cout << "Task ID: " << task.getId() << endl;
    cout << "Name: " << task.getName() << endl;
    cout << "Priority: " << task.getPriority() << endl;
    cout << "Due Date: " << task.getDueDate() << endl;
    cout << "Status: " << task.getStatus() << endl;
    cout << "Progress: " << task.getProgress() << "%" << endl;
    cout << "Dependencies: ";
    for (int dep : task.getDependencies()) {
        cout << dep << " ";
    }
    cout << endl;
}