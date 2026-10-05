EventPlanner* create_event_planner() {
    EventPlanner *planner = (EventPlanner*)malloc(sizeof(EventPlanner));
    if (planner == NULL) return NULL;
    planner->event_type = NULL;
    planner->guest_count = 0;
    planner->budget = 0.0;
    planner->preferred_date = NULL;
    planner->venue = NULL;
    planner->specific_requirements = NULL;
    return planner;
}