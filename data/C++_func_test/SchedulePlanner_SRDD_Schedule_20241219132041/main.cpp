int main() {
    Schedule schedule;
    Reminder reminder;
    ReportGenerator reportGenerator;
    VisualSchedule visualSchedule;
    Task task1("Complete project", 1, "09:00-11:00", false);
    Task task2("Team meeting", 2, "11:30-12:30", false);
    Task task3("Lunch break", 3, "12:30-13:30", false);
    schedule.addTask(task1);
    schedule.addTask(task2);
    schedule.addTask(task3);
    reminder.scheduleReminder(task1, "08:50");
    reminder.scheduleReminder(task2, "11:20");
    reminder.scheduleReminder(task3, "12:20");
    schedule.updateTaskStatus("Complete project", true);
    reportGenerator.generateReport(schedule);
    visualSchedule.display(schedule);
    schedule.removeTask("Lunch break");
    std::cout << "\nUpdated Schedule after removing 'Lunch break':\n";
    visualSchedule.display(schedule);
    return 0;
}