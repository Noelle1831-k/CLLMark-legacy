int main() {
    Schedule schedule;
    Reminder reminder;
    Report report;
    TimeBlock timeBlock;
    Task task1;
    task1.setTaskDetails("Task 1", "Description 1", 1, "09:00-10:00");
    schedule.addTask(task1);
    reminder.setReminder(task1, "08:50");
    timeBlock.allocateTimeSlot(task1, "09:00-10:00");
    Task task2;
    task2.setTaskDetails("Task 2", "Description 2", 2, "10:00-11:00");
    schedule.addTask(task2);
    reminder.setReminder(task2, "09:50");
    timeBlock.allocateTimeSlot(task2, "10:00-11:00");
    schedule.displaySchedule();
    reminder.checkReminders();
    report.generateReport(schedule);
    report.displayReport();
    return 0;
}