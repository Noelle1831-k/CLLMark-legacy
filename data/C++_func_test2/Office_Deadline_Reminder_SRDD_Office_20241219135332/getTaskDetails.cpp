string Task::getTaskDetails() {
    return "Task ID: " + to_string(taskID) + "\nTask Name: " + taskName + "\nDescription: " + description + "\nDeadline: " + ctime(&deadline) + "\nCompleted: " + (isCompleted ? "Yes" : "No");
}