void free_progression_plan(ProgressionPlan *plan) {
    if (plan != NULL) {
        free(plan->steps);
        free(plan);
    }
}