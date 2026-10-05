void set_reminder(Reminder *reminder, int achievement_id, const char *reminder_time, const char *message) {
    reminder->achievement_id = achievement_id;
    strcpy(reminder->reminder_time, reminder_time);
    strcpy(reminder->message, message);
}