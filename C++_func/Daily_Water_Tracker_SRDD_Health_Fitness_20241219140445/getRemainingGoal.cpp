int WaterTracker::getRemainingGoal() {
    return (dailyGoal > totalIntake) ? (dailyGoal - totalIntake) : 0;
}