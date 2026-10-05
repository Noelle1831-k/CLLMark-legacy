int main() {
    User user1("Alice", "Project Manager");
    User user2("Bob", "Developer");
    Task task1("Design", "Design the project architecture", "2023-12-01", "Pending", "High");
    Task task2("Implementation", "Implement the project modules", "2023-12-15", "Pending", "Medium");
    user1.assignTask(task1);
    user2.assignTask(task2);
    Project project("Project Tracker", "A tool to track and manage projects");
    project.addTask(task1);
    project.addTask(task2);
    ReportGenerator reportGen;
    reportGen.generateReport(project);
    Collaboration collab;
    collab.sendMessage(user1, user2, "Let's meet to discuss the project progress.");
    collab.scheduleMeeting(user1, user2, "2023-11-20", "10:00 AM");
    cout << "\nTasks assigned to " << user1.getUserName() << " (" << user1.getRole() << "):" << endl;
    user1.displayTasks();
    cout << "\nTasks assigned to " << user2.getUserName() << " (" << user2.getRole() << "):" << endl;
    user2.displayTasks();
    return 0;
}