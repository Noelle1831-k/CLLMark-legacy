int main() {
    Schedule schedule;
    initializeSchedule(&schedule);
    Task task1 = createTask(1, "Task 1", "Description 1", "2023-12-01", "09:00-11:00", 0);
    Task task2 = createTask(2, "Task 2", "Description 2", "2023-12-02", "11:00-13:00", 0);
    addTask(&schedule, task1);
    addTask(&schedule, task2);
    displaySchedule(&schedule);
    generateReport(&schedule);
    return 0;
}