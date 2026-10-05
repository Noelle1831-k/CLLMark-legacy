int main() {
    TaskManager taskManager;
    UserAnalyzer userAnalyzer;
    taskManager.addTask("Complete project report", 3, "2023-11-01");
    taskManager.addTask("Doctor's appointment", 2, "2023-10-25");
    taskManager.addTask("Grocery shopping", 5, "2023-10-20");
    taskManager.addTask("Team meeting", 4, "2023-10-22");
    userAnalyzer.analyzeTasks(taskManager);
    cout << "Tasks after analysis and priority adjustment:" << endl;
    taskManager.displayTasks();
    return 0;
}