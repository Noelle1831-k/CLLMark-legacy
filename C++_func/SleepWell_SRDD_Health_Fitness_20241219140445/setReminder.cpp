void Reminder::setReminder(User &user) {
    int goal = user.getSleepGoal();
    std::cout << "Setting reminder to ensure you get " << goal << " hours of sleep." << std::endl;
    std::cout << "Reminder: Go to bed by 10:00 PM to meet your sleep goal!" << std::endl;
}