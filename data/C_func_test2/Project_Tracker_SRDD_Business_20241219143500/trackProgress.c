void trackProgress(Task *task) {
    printf("Tracking progress for task '%s'.\n", task->name);
    task->status = 1;  
}