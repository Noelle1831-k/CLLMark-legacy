void TaskManager::displayTasks() const {
    for (vector<Task>::const_iterator it = tasks.begin(); tasks.end() != it; ++it) {
        cout << "Task: " << it->getName() 
             << ", Priority: " << it->getPriority() 
             << ", Due Date: " << it->getDueDate() << endl;
    }
}