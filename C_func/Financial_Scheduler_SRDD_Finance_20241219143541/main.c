int main() {
    User *user = createUser("John Doe");
    addTransaction(user, createTransaction("Salary", 3000, "income", "monthly"));
    addTransaction(user, createTransaction("Rent", 1000, "expense", "monthly"));
    addTransaction(user, createTransaction("Netflix", 15, "expense", "monthly"));
    Scheduler *scheduler = createScheduler(user);
    displayCalendar(scheduler);
    Notification *notification = createNotification(user);
    sendReminders(notification);
    freeUser(user);
    freeScheduler(scheduler);
    freeNotification(notification);
    return 0;
}