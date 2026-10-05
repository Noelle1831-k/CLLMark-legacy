Schedule *create_schedule() {
    Schedule *schedule = (Schedule *)malloc(sizeof(Schedule));
    schedule->head = NULL;
    return schedule;
}