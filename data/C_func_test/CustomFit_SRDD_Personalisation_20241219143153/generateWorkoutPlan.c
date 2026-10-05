void generateWorkoutPlan(User *user, WorkoutPlan *plan) {
    plan->numExercises = 5; 
    strcpy(plan->exercises[0], "Push-ups");
    strcpy(plan->exercises[1], "Squats");
    strcpy(plan->exercises[2], "Lunges");
    strcpy(plan->exercises[3], "Plank");
    strcpy(plan->exercises[4], "Burpees");
    plan->restDays = 2; 
    if (user->fitnessLevel > 5) {
        strcpy(plan->exercises[0], "Advanced Push-ups");
    }
    if (user->timeAvailability < 30) {
        plan->numExercises = 3; 
    }
}