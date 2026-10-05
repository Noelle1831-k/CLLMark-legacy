int main() {
    WorkloadManager manager;
    manager.addEmployee(1, "Alice", "Software Development", 40);
    manager.addEmployee(2, "Bob", "Data Analysis", 35);
    manager.addEmployee(3, "Charlie", "Project Management", 30);
    manager.addTask(101, "Develop Feature A", "Software Development", 20);
    manager.addTask(102, "Analyze Data Set", "Data Analysis", 15);
    manager.addTask(103, "Prepare Project Plan", "Project Management", 10);
    manager.assignTasks();
    manager.generateReport();
    return 0;
}