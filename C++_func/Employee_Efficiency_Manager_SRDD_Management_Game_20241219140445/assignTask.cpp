void Employee::assignTask(Task task) {
    assignedTasks.push_back(task);
    cout << "Task assigned to " << name << ": " << task.getDescription() << endl;
}