string Reminder::getReminderDetails() {
    return "Reminder ID: " + to_string(reminderID) + "\nTask ID: " + to_string(taskID) + "\nReminder Time: " + ctime(&reminderTime);
}