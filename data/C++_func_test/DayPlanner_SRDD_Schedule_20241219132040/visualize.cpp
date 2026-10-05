void Visualizer::visualize(const vector<Task>& tasks) const {
    cout << "\n=== Day Overview ===\n";
    for (const auto& task : tasks) {
        cout << "Task: " << task.getTitle() << " | Category: " << task.getCategory()
             << " | Priority: " << task.getPriority() << endl;
    }
}