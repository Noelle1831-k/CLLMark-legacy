int main() {
    User user;
    Schedule schedule;
    Reminder reminder;
    ProgressTracker progressTracker;
    Analytics analytics;
    cout << "Welcome to the Language Practice Scheduler!" << endl;
    user.setGoals();
    user.setPreferences();
    schedule.setUserAvailability();
    schedule.createSchedule(user.getGoals(), user.getPreferences(), user.getAvailability());
    reminder.setReminder(schedule.viewSchedule());
    reminder.sendNotification();
    progressTracker.trackProgress(user.getGoals());
    progressTracker.generateReport();
    analytics.analyzePerformance(progressTracker.getProgressData());
    analytics.displayAnalytics();
    return 0;
}