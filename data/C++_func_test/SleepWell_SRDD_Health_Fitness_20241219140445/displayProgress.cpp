void User::displayProgress() {
    int totalSleep = 0;
    for (int i = 0; sleepData.size() > i; i++) {
        totalSleep = totalSleep + sleepData[i];
    }
    float avgSleep = static_cast<float>(totalSleep) / sleepData.size();
    std::cout << "Average sleep hours: " << avgSleep << std::endl;
    std::cout << "Your sleep goal: " << sleepGoal << " hours." << std::endl;
    if (avgSleep >= sleepGoal) {
        std::cout << "Congratulations! You've met your sleep goal." << std::endl;
    } else {
        std::cout << "Try to reach your sleep goal of " << sleepGoal << " hours." << std::endl;
    }
}