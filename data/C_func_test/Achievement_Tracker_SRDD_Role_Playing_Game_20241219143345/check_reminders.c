void check_reminders(Reminder *reminders, int count) {
    for (int i = 0; i < count; i++) {
        printf("Reminder for Achievement %d: %s at %s\n", reminders[i].achievement_id, reminders[i].message, reminders[i].reminder_time);
    }
}