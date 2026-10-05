void Schedule::generateReports() const {
    cout << "Generating report..." << endl;
    for (const auto& task : tasks) {
        cout << "Task Name: " << task.getName() << ", Status: " << task.getStatus() << endl;
    }
}