void checkReminders(TaskManager& taskManager, NotificationManager& notificationManager) {
    while (true) {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int currentHour = localTime->tm_hour;
        int currentMinute = localTime->tm_min;
        for (size_t i = 0; i < taskManager.getTaskCount(); ++i) {
            Task task = taskManager.getTask(i);
            if (task.getHour() == currentHour && task.getMinute() == currentMinute && !task.getStatus()) {
                notificationManager.triggerReminder(task);
            }
        }
        this_thread::sleep_for(chrono::seconds(30)); 
    }
}