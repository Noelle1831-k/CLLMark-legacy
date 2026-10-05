void initializeUser(User *user) {
    user->fitnessLevel = 0;
    user->targetGoals = 0;
    strcpy(user->preferredExercises, "");
    user->timeAvailability = 0;
}