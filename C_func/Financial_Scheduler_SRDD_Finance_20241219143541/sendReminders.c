void sendReminders(Notification *notification) {
    printf("Sending reminders to %s:\n", notification->user->name);
    for (int i = 0; i < notification->user->transactionCount; i++) {
        Transaction *transaction = notification->user->transactions[i];
        printf("Reminder: %s is due soon.\n", transaction->name);
    }
}