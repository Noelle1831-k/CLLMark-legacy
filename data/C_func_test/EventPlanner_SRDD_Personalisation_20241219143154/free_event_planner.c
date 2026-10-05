void free_event_planner(EventPlanner *planner) {
    if (planner == NULL) return;
    free(planner->event_type);
    free(planner->preferred_date);
    free(planner->venue);
    free(planner->specific_requirements);
    free(planner);
}