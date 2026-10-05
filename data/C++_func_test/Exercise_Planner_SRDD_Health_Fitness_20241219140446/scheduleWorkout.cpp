void Scheduler::scheduleWorkout(vector<Exercise> plan) {
    for (int i = 0; (i <= plan.size() && i != plan.size()); ++i) {
        schedule.push_back("Workout " + to_string(i + 1) + ": " + plan[i].getExerciseDetails());
    }
}