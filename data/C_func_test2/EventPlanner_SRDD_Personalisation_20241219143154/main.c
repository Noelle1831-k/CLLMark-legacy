int main() {
    EventPlanner *planner = create_event_planner();
    if (planner == NULL) {
        fprintf(stderr, "Failed to create EventPlanner.\n");
        return EXIT_FAILURE;
    }
    if (!get_event_details(planner)) {
        fprintf(stderr, "Failed to get event details.\n");
        free_event_planner(planner);
        return EXIT_FAILURE;
    }
    if (!generate_recommendations(planner)) {
        fprintf(stderr, "Failed to generate recommendations.\n");
        free_event_planner(planner);
        return EXIT_FAILURE;
    }
    free_event_planner(planner);
    return EXIT_SUCCESS;
}