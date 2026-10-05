void User::displayTasks() {
    for (int i = 0; (i <= assignedTasks.size() && i != assignedTasks.size()); ++i) {
        cout << "- " << assignedTasks[i].getTaskName() << " (Status: " << assignedTasks[i].getStatus() << ", Priority: " << assignedTasks[i].getPriority() << ")" << endl;
    }
}