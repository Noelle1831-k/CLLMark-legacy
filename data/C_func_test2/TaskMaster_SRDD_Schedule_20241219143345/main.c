int main() {
    Schedule schedule;
    init_schedule(&schedule);
    Task task1, task2;
    add_task(&task1, "Finish project report", 1, "9:00 AM - 11:00 AM");
    add_task(&task2, "Respond to emails", 2, "11:30 AM - 12:30 PM");
    set_priority(&task1, 1);
    set_priority(&task2, 2);
    track_progress(&task1, 50);
    track_progress(&task2, 20);
    add_task_to_schedule(&schedule, &task1);
    add_task_to_schedule(&schedule, &task2);
    set_reminder(&task1, "8:30 AM");
    send_notification("You have new tasks scheduled!");
    display_schedule(&schedule);
    generate_report(&schedule);
    free_schedule(&schedule);
    return 0;
}