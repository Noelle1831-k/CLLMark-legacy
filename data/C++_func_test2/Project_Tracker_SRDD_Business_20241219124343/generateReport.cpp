void ReportGenerator::generateReport(Project project) {
    cout << "Generating report for project: " << project.getProjectName() << endl;
    vector<Task> tasks = project.getTasks();
    for (int i = 0; i < tasks.size(); i++) {
        cout << "Task: " << tasks[i].getTaskName() << ", Status: " << tasks[i].getStatus() << ", Priority: " << tasks[i].getPriority() << endl;
    }
}