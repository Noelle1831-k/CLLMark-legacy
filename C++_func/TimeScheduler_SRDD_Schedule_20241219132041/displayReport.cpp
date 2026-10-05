void Report::displayReport() const {
    cout << "Displaying report..." << endl;
    cout << "Total number of tasks: " << totalTasks << endl;
    cout << "Number of completed tasks: " << completedTasks << endl;
    cout << "Priority distribution: " << endl;
    for (int i = 0; i < priorityDistribution.size(); ++i) {
        cout << "Priority " << (i + 1) << ": " << priorityDistribution[i] << " tasks" << endl;
    }
}