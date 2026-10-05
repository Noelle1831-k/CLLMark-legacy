void Schedule::updateTask(int id) {
    for (auto &task : tasks) {
        if (task.getId() == id) {
            cout << "Updating Task ID " << id << ". Enter new status: ";
            string status;
            cin.ignore();
            getline(cin, status);
            task.setStatus(status);
            cout << "Task updated successfully.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}