int main() {
    TaskManager taskManager;
    ReportGenerator reportGenerator;
    Visualization visualization;
    taskManager.addTask("Design Module", "Development", "2023-12-01");
    taskManager.addTask("Write Documentation", "Documentation", "2023-11-15");
    taskManager.addTask("Code Review", "Development", "2023-11-20");
    taskManager.findTaskById(1)->addTimeSpent(2);
    taskManager.findTaskById(1)->markCompleted();
    taskManager.findTaskById(2)->addTimeSpent(1);
    taskManager.findTaskById(3)->addTimeSpent(3);
    taskManager.displayAllTasks();
    reportGenerator.generateTimeAllocationReport(taskManager);
    reportGenerator.generateEfficiencyReport(taskManager);
    visualization.displayProgressChart(taskManager);
    visualization.displayEfficiencyChart(taskManager);
    return 0;
}