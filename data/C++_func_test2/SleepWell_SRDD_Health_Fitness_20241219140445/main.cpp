int main() {
    std::string name;
    int age;
    int goal_hours;
    std::cout << "Welcome to SleepWell!" << std::endl;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Enter your sleep goal in hours: ";
    std::cin >> goal_hours;
    User user(name, age, goal_hours);
    SleepTracker tracker;
    SleepRecommendation recommender;
    Reminder reminder;
    Relaxation relaxation;
    int hours_slept;
    std::cout << "Enter hours slept last night: ";
    std::cin >> hours_slept;
    tracker.trackSleep(hours_slept);
    user.addSleepData(hours_slept);
    recommender.provideRecommendation(user);
    reminder.setReminder(user);
    relaxation.suggestRelaxation();
    user.displayProgress();
    return 0;
}