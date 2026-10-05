void plan_activity(User *organizer, User *participant, const char *description) {
    Activity activity;
    strcpy(activity.organizer, organizer->name);
    strcpy(activity.participant, participant->name);
    strcpy(activity.description, description);
    printf("Activity planned by %s with %s: %s\n", activity.organizer, activity.participant, activity.description);
}