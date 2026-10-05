void Dashboard::assignTask() {
    int taskId;
    string assignee;
    cout << "Enter Task ID to assign: ";
    cin >> taskId;
    cin.ignore();
    cout << "Enter Assignee Name: ";
    getline(cin, assignee);
    for (auto& project : projects) {
        for (Task& task : project.tasks) {
            if (task.getTaskId() == taskId) {
                task.setAssignee(assignee);
                cout << "Task assigned successfully!" << endl;
                return;
            }
        }
    }
    cout << "Task not found!" << endl;
}