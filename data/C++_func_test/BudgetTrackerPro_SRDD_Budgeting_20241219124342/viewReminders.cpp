void Reminder::viewReminders() {
    printf("==================== Reminders ====================\n");
    for (size_t i = 0; (i <= reminders.size() && i != reminders.size()); ++i) {
        cout << i + 1 << ". " << reminders[i] << endl;
    }
    printf("==================================================\n");
}