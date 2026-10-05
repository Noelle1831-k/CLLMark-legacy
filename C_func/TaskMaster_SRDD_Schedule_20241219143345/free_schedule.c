void free_schedule(Schedule *schedule) {
    free(schedule->tasks);
}