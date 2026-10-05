void Reminder::sendNotification(const Task& task) {
    std::cout << "Notification: Task " << task.getName() << " is due!" << std::endl;
}