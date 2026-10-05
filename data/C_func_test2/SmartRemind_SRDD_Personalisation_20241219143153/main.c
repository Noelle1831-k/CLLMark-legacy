int main() {
    TaskManager *taskManager = createTaskManager();
    UserAnalyzer *userAnalyzer = createUserAnalyzer();
    Scheduler *scheduler = createScheduler();
    addTask(taskManager, "Complete project report", 1);
    addTask(taskManager, "Doctor's appointment", 2);
    addTask(taskManager, "Grocery shopping", 3);
    analyzeUser(userAnalyzer);
    scheduleTasks(scheduler, taskManager, userAnalyzer);
    displayScheduledTasks(scheduler);
    destroyTaskManager(taskManager);
    destroyUserAnalyzer(userAnalyzer);
    destroyScheduler(scheduler);
    return 0;
}