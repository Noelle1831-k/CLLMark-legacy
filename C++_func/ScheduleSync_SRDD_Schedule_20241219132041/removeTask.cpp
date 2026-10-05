void Schedule::removeTask(string taskName) {
    vector<Task>::iterator it;
    for (it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == taskName) {
            tasks.erase(it);
            cout << "Task removed successfully." << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}