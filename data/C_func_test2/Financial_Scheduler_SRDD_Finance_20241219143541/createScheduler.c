Scheduler *createScheduler(User *user) {
    Scheduler *scheduler = (Scheduler *)malloc(sizeof(Scheduler));
    scheduler->user = user;
    return scheduler;
}