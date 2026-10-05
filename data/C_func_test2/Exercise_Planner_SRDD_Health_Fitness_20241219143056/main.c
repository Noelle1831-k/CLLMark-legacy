int main() {
    printf("Welcome to the Exercise Planner!\n");
    User user = createUser();
    inputUserGoals(&user);
    ExercisePlan plan = generatePlan(user);
    displayPlan(plan);
    Schedule schedule = createSchedule(plan);
    displaySchedule(schedule);
    while (1) {
        sendNotifications(schedule);
        updateSchedule(&schedule);
        sleep(60); 
    }
    return 0;
}