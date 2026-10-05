int main() {
    TaskAllocator allocator;
    allocator.addEmployee(Employee(1, "Alice", {"C++", "Java"}, 0));
    allocator.addEmployee(Employee(2, "Bob", {"Python", "SQL"}, 0));
    allocator.addEmployee(Employee(3, "Charlie", {"JavaScript", "HTML"}, 0));
    allocator.addTask(Task(1, "Develop feature X", {"C++"}, "2023-11-01", "Pending"));
    allocator.addTask(Task(2, "Fix bug Y", {"Python"}, "2023-11-05", "Pending"));
    allocator.addTask(Task(3, "Design UI", {"HTML"}, "2023-11-10", "Pending"));
    allocator.addTask(Task(4, "Database Optimization", {"SQL"}, "2023-11-15", "Pending"));
    allocator.assignTasks();
    allocator.generateReport();
    return 0;
}