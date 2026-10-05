void scheduleTasks(Scheduler *scheduler, TaskManager *taskManager, UserAnalyzer *userAnalyzer) {
    struct Task *currentTask = taskManager->head;
    while (currentTask != NULL) {
        struct ScheduledTask *newScheduledTask = (struct ScheduledTask*)malloc(sizeof(struct ScheduledTask));
        strcpy(newScheduledTask->description, currentTask->description);
        newScheduledTask->priority = currentTask->priority + userAnalyzer->analysisData;
        newScheduledTask->next = scheduler->head;
        scheduler->head = newScheduledTask;
        currentTask = currentTask->next;
    }
}