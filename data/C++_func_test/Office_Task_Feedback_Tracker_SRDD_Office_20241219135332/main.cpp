int main() {
    FeedbackSystem system;
    system.addEmployee(1, "Alice");
    system.addEmployee(2, "Bob");
    system.addTask(101, "Develop Feature X");
    system.addTask(102, "Fix Bug Y");
    system.getEmployee(1)->submitFeedback(101, "The task is well-defined but needs more time.", "concern");
    system.getEmployee(2)->submitFeedback(102, "The bug is tricky, might need a different approach.", "suggestion");
    system.getManager()->viewTaskFeedback(101);
    system.getManager()->viewEmployeeFeedback(2);
    return 0;
}