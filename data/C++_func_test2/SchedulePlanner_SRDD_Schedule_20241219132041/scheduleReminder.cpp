void Reminder::scheduleReminder(const Task& task, const std::string& reminderTime) {
    std::cout << "Reminder set for task: " << task.getName() << " at " << reminderTime << std::endl;
}