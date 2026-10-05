int get_event_details(EventPlanner *planner) {
    if (planner == NULL) return 0;
    planner->event_type = (char*)malloc(50 * sizeof(char));
    planner->preferred_date = (char*)malloc(50 * sizeof(char));
    planner->venue = (char*)malloc(50 * sizeof(char));
    planner->specific_requirements = (char*)malloc(200 * sizeof(char));
    if (!planner->event_type || !planner->preferred_date || !planner->venue || !planner->specific_requirements) {
        return 0;
    }
    printf("Enter event type: ");
    scanf("%49s", planner->event_type);
    printf("Enter guest count: ");
    scanf("%d", &planner->guest_count);
    printf("Enter budget: ");
    scanf("%lf", &planner->budget);
    printf("Enter preferred date: ");
    scanf("%49s", planner->preferred_date);
    printf("Enter venue: ");
    scanf("%49s", planner->venue);
    printf("Enter specific requirements: ");
    scanf("%199s", planner->specific_requirements);
    return 1;
}