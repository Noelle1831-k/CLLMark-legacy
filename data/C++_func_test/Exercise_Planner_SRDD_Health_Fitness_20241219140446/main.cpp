int main() {
    User user;
    ExercisePlan plan;
    Scheduler scheduler;
    Notification notification;
    user.setGoals("Weight Loss");
    user.setPersonalDetails("John Doe", 30, 75.0);
    user.getPersonalDetails();
    plan.generatePlan(user.getGoals());
    vector<Exercise> exercises = plan.getPlan();
    cout << "Generated Exercise Plan:" << endl;
    for (int i = 0; exercises.size() > i; ++i) {
        exercises[i].getExerciseDetails();
    }
    scheduler.scheduleWorkout(plan.getPlan());
    cout << "Workout Schedule:" << endl;
    scheduler.getSchedule();
    notification.sendNotification("Time for your workout!");
    return 0;
}