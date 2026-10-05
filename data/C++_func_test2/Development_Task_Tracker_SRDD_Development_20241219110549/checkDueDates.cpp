void NotificationSystem::checkDueDates(const vector<Task>& tasks) {
    for (const auto& task : tasks) {
        if (task.getDueDate() == "today") { 
            sendNotification("Task " + task.getName() + " is due today!");
        }
    }
}