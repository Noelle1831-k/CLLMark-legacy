void WorkoutPlan::generatePlan(const string &sport, const string &goal) {
    exercises.clear();
    if (sport == "running") {
        exercises.push_back("Warm-Up: 10 minutes jogging");
        exercises.push_back("Interval Training: 5x400m sprints");
        exercises.push_back("Cool-Down: 15 minutes stretching");
    } else if (sport == "weightlifting") {
        exercises.push_back("Warm-Up: 5 minutes cardio");
        exercises.push_back("Deadlift: 3x8 reps");
        exercises.push_back("Squat: 4x10 reps");
    } else {
        exercises.push_back("General Workout: 30 minutes moderate intensity");
    }
}