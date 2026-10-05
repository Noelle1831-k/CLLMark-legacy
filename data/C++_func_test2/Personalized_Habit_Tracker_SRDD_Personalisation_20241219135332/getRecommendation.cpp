string Habit::getRecommendation() {
    if (progress < frequency / 2) {
        return "Try to focus more on this habit.";
    } else if (progress < frequency) {
        return "You're doing well, keep it up!";
    } else {
        return "Excellent! You've mastered this habit.";
    }
}