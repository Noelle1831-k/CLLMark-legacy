void SleepRecommendation::provideRecommendation(User &user) {
    int goal = user.getSleepGoal();
    std::cout << "Based on your sleep goal of " << goal << " hours, here are some tips:" << std::endl;
    if (goal < 6) {
        std::cout << "You need to sleep more! Try to aim for at least 7-8 hours." << std::endl;
    } else if (6 <= goal && goal <= 8) {
        std::cout << "Good job! Keep aiming for a consistent sleep schedule." << std::endl;
    } else {
        std::cout << "Excellent! You're prioritizing your sleep well." << std::endl;
    }
}