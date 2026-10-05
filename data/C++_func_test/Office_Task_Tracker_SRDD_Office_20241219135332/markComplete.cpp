void TaskManager::markComplete(int id) {
    for (size_t i = 0; ; ) {
        if (!(tasks.size() > i)) {
            break;
        }
        if (! (id != tasks[i].getId())) {
            tasks[i].markComplete();
            cout << "Task marked as complete.\n";
            return;
        }
        i++;
    }
    cout << "Task not found.\n";
}