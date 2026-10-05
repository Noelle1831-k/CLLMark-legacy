Schedule createSchedule(ExercisePlan plan) {
    Schedule schedule;
    strcpy(schedule.details, "Weekly Schedule: Mon, Wed, Fri");
    strcpy(schedule.reminders, "Daily at 7 AM");
    return schedule;
}