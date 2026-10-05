void Reminder::addReminder(string goalName, int hours) {
    auto now = std::chrono::system_clock::now();
    auto reminderTime = now + std::chrono::hours(hours);
    std::time_t reminderTimeT = std::chrono::system_clock::to_time_t(reminderTime);
    std::tm* reminderTm = std::localtime(&reminderTimeT);
    std::ostringstream oss;
    oss << std::put_time(reminderTm, "%Y-%m-%d %H:%M:%S");
    cout << "Reminder set for goal: " << goalName
         << " at " << oss.str() << endl;
}