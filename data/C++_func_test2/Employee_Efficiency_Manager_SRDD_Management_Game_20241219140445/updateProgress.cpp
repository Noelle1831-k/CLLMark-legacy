void Employee::updateProgress() {
    for (int i = 0; i < assignedTasks.size(); i++) {
        if (assignedTasks[i].getStatus() == "Pending") {
            assignedTasks[i].updateStatus();
            completedTasks++;
        }
    }
}