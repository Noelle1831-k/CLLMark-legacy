void Scheduler::removeTask(int id) {
    if (id < 0 || id >= tasks.size()) {
        cout << "Invalid Task ID!" << endl;
        return;
    }
    tasks.erase(tasks.begin() + id);
}