Scheduler* createScheduler() {
    Scheduler *scheduler = (Scheduler*)malloc(sizeof(Scheduler));
    scheduler->head = NULL;
    return scheduler;
}