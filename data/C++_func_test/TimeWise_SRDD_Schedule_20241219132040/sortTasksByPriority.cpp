void Schedule::sortTasksByPriority() {
    sort(tasks.begin(), tasks.end(), [](Task &a, Task &b) { return a.getPriority() < b.getPriority(); });
    cout << "Tasks sorted by priority.\n";
}